#ifndef LAYERSDEMOWINDOW_H
#define LAYERSDEMOWINDOW_H

#include <Layers/lmainwindow.h>

class LayersDemoWindow : public Layers::LMainWindow
{
	Q_OBJECT

public:
	LayersDemoWindow(bool preview = false, QWidget* parent = nullptr);

	virtual LThemeable* clone() override;

private:
};

#endif // LAYERSDEMOWINDOW_H
