#ifndef IMAGESEQUENCE_H
#define IMAGESEQUENCE_H

#include <QDir>

namespace Layers
{
	/*!
		An ImageSequence is a series of images that are arranged in a specific
		order and played back in sequence to create the illusion of motion.

		An image sequence can be loaded from a directory of images or from a
		single file with the *imgseq* filename extension.
	*/
	class ImageSequence
	{
	public:
		/*!
			Constructs an image sequence from a directory specified by *dir*.
		*/
		ImageSequence(QDir dir);

		/*!
			Constructs an image sequence from a file specified by *file*.
		*/
		ImageSequence(QFile file);

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

#endif // IMAGESEQUENCE_H
