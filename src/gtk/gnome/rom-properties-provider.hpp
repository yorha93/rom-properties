/***************************************************************************
 * ROM Properties Page shell extension. (GNOME)                            *
 * rom-properties-provider.hpp: Nautilus (and forks) Provider Definition.  *
 *                                                                         *
 * Copyright (c) 2017-2020 by David Korth.                                 *
 * SPDX-License-Identifier: GPL-2.0-or-later                               *
 ***************************************************************************/

#ifndef __ROMPROPERTIES_GNOME_ROM_PROPERTIES_PROVIDER_HPP__
#define __ROMPROPERTIES_GNOME_ROM_PROPERTIES_PROVIDER_HPP__

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _RomPropertiesProviderClass	RomPropertiesProviderClass;
typedef struct _RomPropertiesProvider		RomPropertiesProvider;

#define TYPE_ROM_PROPERTIES_PROVIDER		(rom_properties_provider_get_type())
#define ROM_PROPERTIES_PROVIDER(obj)		(G_TYPE_CHECK_INSTANCE_CAST((obj), TYPE_ROM_PROPERTIES_PROVIDER, RomPropertiesProvider))
#define ROM_PROPERTIES_PROVIDER_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST((klass),  TYPE_ROM_PROPERTIES_PROVIDER, RomPropertiesProviderClass))
#define IS_ROM_PROPERTIES_PROVIDER(obj)		(G_TYPE_CHECK_INSTANCE_TYPE((obj), TYPE_ROM_PROPERTIES_PROVIDER))
#define IS_ROM_PROPERTIES_PROVIDER_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE((klass),  TYPE_ROM_PROPERTIES_PROVIDER))
#define ROM_PROPERTIES_PROVIDER_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS((obj),  TYPE_ROM_PROPERTIES_PROVIDER, RomPropertiesProviderClass))

/* these two functions are implemented automatically by the G_DEFINE_DYNAMIC_TYPE macro */
GType		rom_properties_provider_get_type	(void) G_GNUC_CONST G_GNUC_INTERNAL;
/* NOTE: G_DEFINE_DYNAMIC_TYPE() declares the actual function as static. */
void		rom_properties_provider_register_type_ext(GTypeModule *module) G_GNUC_INTERNAL;

G_END_DECLS

#endif /* !__ROMPROPERTIES_GNOME_ROM_PROPERTIES_PROVIDER_HPP__ */
