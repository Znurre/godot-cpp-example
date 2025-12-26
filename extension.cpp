#include "node.hpp"

#include <gdextension_interface.h>

namespace
{
	void initialize_extension(godot::ModuleInitializationLevel p_level)
	{
		switch (p_level)
		{
		case godot::MODULE_INITIALIZATION_LEVEL_SCENE: {
            // Add your registrations here.
            //
            GDREGISTER_RUNTIME_CLASS(MyNode);

            break;
        }

        default:
            break;
        }
    }

    void uninitialize_extension(godot::ModuleInitializationLevel p_level)
	{
		if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE)
		{
			return;
		}
	}
}

extern "C"
{
// Note how this function has the name we specified in our gdextension file.
//
GDExtensionBool GDE_EXPORT gd_extension_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                                             GDExtensionClassLibraryPtr p_library,
                                             GDExtensionInitialization *r_initialization)
{
    godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

    init_obj.register_initializer(initialize_extension);
    init_obj.register_terminator(uninitialize_extension);
    init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_CORE);

    return init_obj.init();
}
}
