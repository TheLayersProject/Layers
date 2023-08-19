#ifndef LSPLITTER_H
#define LSPLITTER_H

#include <QSplitter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	\htmlonly
		<video style="max-width:100%;height:auto;" width="356" height="256"
		autoplay loop muted disableRemotePlayback>
			<source src="splitter.mp4" type="video/mp4">
			Your browser does not support the video tag.
		</video>
	\endhtmlonly
	
	An LSplitter is a QSplitter and an LThemeable that gives the user a way to
	resize child widgets by click-dragging a control between them.
*/
class LSplitter : public QSplitter, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a splitter.
	*/
	LSplitter(QWidget* parent = nullptr);

	/*!
		Constructs a splitter with the provided *orientation*.
	*/
	LSplitter(Qt::Orientation orientation, QWidget* parent = nullptr);

private:
	void init();
};
LAYERS_NAMESPACE_END

#endif // LSPLITTER_H
