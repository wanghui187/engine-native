#include "GLES2Std.h"
#include "GLES2Context.h"
#include "gles2w.h"
#import <QuartzCore/CAEAGLLayer.h>
#import <UIKit/UIScreen.h>
#import <QuartzCore/QuartzCore.h>

NS_CC_BEGIN

#if (CC_PLATFORM == CC_PLATFORM_MAC_IOS)

bool GLES2Context::Initialize(const GFXContextInfo &info) {
  
    vsync_mode_ = info.vsync_mode;
    window_handle_ = info.window_handle;

    //////////////////////////////////////////////////////////////////////////

    if (!info.shared_ctx) {
        is_primary_ctx_ = true;
        window_handle_ = info.window_handle;

        EAGLContext* eagl_context = [[EAGLContext alloc]initWithAPI:kEAGLRenderingAPIOpenGLES2];
        if (!eagl_context) {
            CC_LOG_ERROR("Create EAGL context failed.");
            return false;
        }

        eagl_context_ = (intptr_t)eagl_context;
        eagl_shared_ctx_ = (intptr_t)eagl_context;

        if (!gles2wInit())
            return false;
    } else {
        GLES2Context* shared_ctx = (GLES2Context*)info.shared_ctx;
        EAGLContext* eagl_shared_context = (EAGLContext*)shared_ctx->eagl_shared_ctx();
        EAGLContext* eagl_context = [[EAGLContext alloc] initWithAPI: [eagl_shared_context API] sharegroup: [eagl_shared_context sharegroup]];
        if (!eagl_context) {
            CC_LOG_ERROR("Create EGL context with share context [0x%p] failed.", eagl_shared_context);

            eagl_context_ = (intptr_t)eagl_context;
            eagl_shared_ctx_ = (intptr_t)eagl_shared_context;

            return false;
        }
    }
    
    color_fmt_ = GFXFormat::RGBA8;
    depth_stencil_fmt_ = GFXFormat::D24S8;

    if (!MakeCurrent())
        return false;
    
    //FIXME: should create custom frame buffer and color buffer. Depth/Stencil attachment are needed, add them in future.
    // Should let default window know it, then when Window::resize() should recreate them.
    GLuint colorBuffer;
    glGenRenderbuffers(1, &colorBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorBuffer);

    CAEAGLLayer* eaglLayer = (CAEAGLLayer*)( ((UIView*)(window_handle_)).layer);
    if (! [(EAGLContext*)eagl_context_ renderbufferStorage:GL_RENDERBUFFER
                                              fromDrawable:eaglLayer])
    {
      CC_LOG_ERROR("Attaches EAGLDrawable as storage for the OpenGL ES renderbuffer object failed.");
      glBindRenderbuffer(GL_RENDERBUFFER, 0);
      glDeleteRenderbuffers(1, &colorBuffer);
      return false;
    }

    GLuint defaulFBO;
    glGenFramebuffers(1, &defaulFBO);
    glBindFramebuffer(GL_FRAMEBUFFER, defaulFBO);
    glBindRenderbuffer(GL_RENDERBUFFER, colorBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorBuffer);

    return true;
}

void GLES2Context::Destroy() {
  
  if (eagl_context_) {
    [(EAGLContext*)eagl_context_ release];
  }

  is_primary_ctx_ = false;
  window_handle_ = 0;
  vsync_mode_ = GFXVsyncMode::OFF;
  is_initialized = false;
}

void GLES2Context::Present() {
  if (! [(EAGLContext*)eagl_context_ presentRenderbuffer:GL_RENDERBUFFER] )
  {
      CC_LOG_ERROR("Failed to present content.");
  }
}

bool GLES2Context::MakeCurrentImpl() {
  return [EAGLContext setCurrentContext:(EAGLContext*)eagl_context_];
}

#endif

NS_CC_END