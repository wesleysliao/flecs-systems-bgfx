#ifndef FLECS_SYSTEMS_BGFX_H
#define FLECS_SYSTEMS_BGFX_H

#include <flecs.h>
#include <flecs_components_gui.h>
#include <flecs_components_input.h>
#include <flecs_systems_sdl2.h>
#include <bgfx/c99/bgfx.h>
#include <SDL2/SDL_syswm.h>

#ifndef flecs_systems_bgfx_STATIC
#if flecs_systems_bgfx_EXPORTS && (defined(_MSC_VER) || defined(__MINGW32__))
#define FLECS_SYSTEMS_BGFX_API __declspec(dllexport)
#elif flecs_systems_bgfx_EXPORTS
#define FLECS_SYSTEMS_BGFX_API __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define FLECS_SYSTEMS_BGFX_API __declspec(dllimport)
#else
#define FLECS_SYSTEMS_BGFX_API
#endif
#else
#define FLECS_SYSTEMS_BGFX_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

FLECS_SYSTEMS_BGFX_API
ECS_STRUCT(BgfxInit, {
  bgfx_init_t init;
});

ECS_COMPONENT_DECLARE(BgfxInit);

FLECS_SYSTEMS_BGFX_API
void FlecsSystemsBgfxImport(ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

namespace flecs {
namespace systems {

class bgfx {
public:
    using Init = BgfxInit;

    bgfx(flecs::world& ecs) {
        // Load module contents
        FlecsSystemsBgfxImport(ecs);

        // Bind module contents with C++ types
        ecs.module<flecs::systems::bgfx>();
        ecs.component<Init>();
    }
};

}
}

#endif // FLECS_NO_CPP
#endif // __cplusplus

#endif
