#ifndef LLABEL_H
#define LLABEL_H

#include <QLabel>
#include <QTimer>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lgraphic.h>
#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LLabel is a QLabel and a LThemeable that is used to display text or an
	LGraphic.
*/
class LAYERS_EXPORT LLabel : public QLabel, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs an empty label.
	*/
	LLabel(QWidget* parent = nullptr);

	/*!
		Constructs a label that displays *text*.
	*/
	LLabel(const QString& text, QWidget* parent = nullptr);

	/*!
		Constructs a label that displays *graphic*.
	*/
	LLabel(const LGraphic& graphic, QWidget* parent = nullptr);

	~LLabel();

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include a
		pointer to the LSvgRenderer, if the label uses a graphic that has one.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	/*!
		Returns a pointer to the fill attribute of the label.
	*/
	LAttribute* fill() const;

	/*!
		Returns a pointer to the label's graphic.

		Returns nullptr if the label does not have a graphic.
	*/
	LGraphic* graphic() const;

	/*!
		Sets the *size* of the label's font.
	*/
	void set_font_size(int size);

	/*!
		Returns the recommended size for the label.
	*/
	virtual QSize sizeHint() const override;

	/*!
		Returns a pointer to the text color attribute of the label.
	*/
	LAttribute* text_color() const;

protected:
	void paintEvent(QPaintEvent* event);

private slots:
	void update_stylesheet();

private:
	void init();
	void init_attributes();

	int m_frame{ 0 };

	LGraphic* m_graphic{ nullptr };

	LAttribute* m_fill{
		new LAttribute("fill", QColor(Qt::white)) };

	LAttribute* m_text_color{
		new LAttribute("text_color", QColor(Qt::black)) };

	QMetaObject::Connection m_repaint_connection;

	QTimer m_timer;
};
LAYERS_NAMESPACE_END

#endif // LLABEL_H
