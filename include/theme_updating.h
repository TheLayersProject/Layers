#ifndef THEME_UPDATING_H
#define THEME_UPDATING_H

#include "old.h"
#include "Theme.h"

namespace Layers
{
	// 2.0.0a -> 2.1.0a
	Theme_2_1_0_a update_theme_2_0_0_a_to_2_1_0_a(Theme_2_0_0_a& old_theme);

	// 2.1.0a -> 2.2.0a
	Theme_2_2_0_a update_theme_2_1_0_a_to_2_2_0_a(Theme_2_1_0_a& old_theme);

	// 2.2.0a -> 2.3.0a (Current)
	Theme update_theme_2_2_0_a_to_2_3_0_a(Theme_2_2_0_a& old_theme);
}

#endif // THEME_UPDATING_H
