/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LAYERS_EXPORTS_H
#define LAYERS_EXPORTS_H

 // Platform-specific checks
#if defined(_WIN32) || defined(_WIN64)
	#define LAYERS_WINDOWS
#endif

// Dynamic linkage handling
#ifndef BUILD_STATIC
	#ifdef LAYERS_WINDOWS
		#ifdef LAYERS_LIB
			#define LAYERS_EXPORT __declspec(dllexport)
		#else
			#define LAYERS_EXPORT __declspec(dllimport)
		#endif
	#else
		#ifdef LAYERS_LIB
			#define LAYERS_EXPORT __attribute__((visibility("default")))
		#else
			#define LAYERS_EXPORT
		#endif
	#endif
#else
	#define LAYERS_EXPORT
#endif

#endif // LAYERS_EXPORTS_H
