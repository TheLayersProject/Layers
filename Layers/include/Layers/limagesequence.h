#ifndef LIMAGESEQUENCE_H
#define LIMAGESEQUENCE_H

#include <QDir>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
/*!
	\htmlonly
		<video style="max-width:100%;height:auto;" width="120" height="120"
		autoplay loop muted disableRemotePlayback>
			<source src="image_sequence.mp4" type="video/mp4">
			Your browser does not support the video tag.
		</video>
	\endhtmlonly
	
	An LImageSequence is a series of images that are arranged in a specific
	order and played back to create the illusion of motion.

	Image sequences are useful for animated icons. The example above is the
	animated *Layers* icon. The advantage over using a video format is that
	sequences can maintain image transparency. 

	An image sequence can be loaded from a directory of images or from a single
	file with the *imgseq* filename extension.
*/
class LAYERS_EXPORT LImageSequence
{
public:
	/*!
		Constructs an image sequence loaded from a *directory*.
	*/
	LImageSequence(QDir directory);

	/*!
		Constructs an image sequence loaded from a *file*.
	*/
	LImageSequence(QFile file);

	/*!
		Returns a pointer to the frame specified by *i*.
	*/
	QImage* frame(int i);

	/*!
		Saves the image sequence to the specified *file*.
	*/
	void save(QFile file);

	/*!
		Returns the number of frames contained in the image sequence.
	*/
	qsizetype size() const;

private:
	QList<QImage> m_frames;
};
LAYERS_NAMESPACE_END

#endif // LIMAGESEQUENCE_H
