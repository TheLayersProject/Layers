#ifndef LIMAGESEQUENCE_H
#define LIMAGESEQUENCE_H

#include <QDir>

#include "layerscoreexports.h"

namespace Layers
{
	/*!
		An LImageSequence is a series of images that are arranged in a specific
		order and played back in sequence to create the illusion of motion.

		An image sequence can be loaded from a directory of images or from a
		single file with the *imgseq* filename extension.
	*/
	class LAYERS_CORE_EXPORT LImageSequence
	{
	public:
		/*!
			Constructs an image sequence from a directory specified by *dir*.
		*/
		LImageSequence(QDir dir);

		/*!
			Constructs an image sequence from a file specified by *file*.
		*/
		LImageSequence(QFile file);

		/*!
			Saves the image sequence to the specified *file*.
		*/
		void save(QFile file);

		/*!
			Returns the number of frames contained in the image sequence.
		*/
		qsizetype size() const;

		/*!
			Returns a reference to the frame specified by *i*.
		*/
		QImage& operator[](int i);

	private:
		QList<QImage> m_frames;
	};
}

#endif // LIMAGESEQUENCE_H
