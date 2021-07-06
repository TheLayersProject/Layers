#include "Layers.h"

using Layers::Image_Sequence_Label;

Image_Sequence_Label::Image_Sequence_Label(QDir dir, QSize size, QWidget* parent) : QLabel(parent)
{
	QStringList image_filenames = dir.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);

	for (QString filename : image_filenames)
	{
		m_image_seq.append(new QPixmap(dir.filePath(filename)));
	}

	setFixedSize(size);

	setPixmap(m_image_seq.value(m_frame_number++)->scaled(size));

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(time_out()));

	m_timer.start(16.6675);
}

Image_Sequence_Label::Image_Sequence_Label(const Image_Sequence_Label& isl)
{
	for (QPixmap* image : isl.m_image_seq)
	{
		m_image_seq.append(new QPixmap(*image));
	}

	setFixedSize(isl.size());

	setPixmap(m_image_seq.value(m_frame_number++)->scaled(size()));

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(time_out()));

	m_timer.start(16.6675);
}

Image_Sequence_Label::~Image_Sequence_Label()
{
	for (QPixmap* image : m_image_seq)
	{
		if (image) delete image;
		image = nullptr;
	}

	m_image_seq.clear();
}

void Image_Sequence_Label::time_out()
{
	setPixmap(m_image_seq.value(m_frame_number++)->scaled(size()));

	if (m_frame_number == m_image_seq.size()) m_frame_number = 0;

	m_timer.start(16.6675);
}
