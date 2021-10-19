#include "../Layers.h"

using Layers::ImageSequenceLabel;

ImageSequenceLabel::ImageSequenceLabel(ImageSequence image_sequence, QSize size, QWidget* parent) :
	m_pixmaps{ image_sequence.to_pixmaps() }, QLabel(parent)
{
	setFixedSize(size);

	setPixmap(m_pixmaps.value(m_frame_number++).scaled(size));

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(time_out()));

	m_timer.start(16.6675);
}

//ImageSequenceLabel::ImageSequenceLabel(QDir dir, QSize size, QWidget* parent) : QLabel(parent)
//{
//	QStringList image_filenames = dir.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);
//
//	for (QString filename : image_filenames)
//	{
//		m_image_seq.append(new QPixmap(dir.filePath(filename)));
//	}
//
//	setFixedSize(size);
//
//	setPixmap(m_image_seq.value(m_frame_number++)->scaled(size));
//
//	connect(&m_timer, SIGNAL(timeout()), this, SLOT(time_out()));
//
//	m_timer.start(16.6675);
//}

ImageSequenceLabel::ImageSequenceLabel(const ImageSequenceLabel& isl)
{
	for (QPixmap pixmap : isl.m_pixmaps)
	{
		m_pixmaps.append(QPixmap(pixmap));
	}

	setFixedSize(isl.size());

	setPixmap(m_pixmaps.value(m_frame_number++).scaled(size()));

	connect(&m_timer, SIGNAL(timeout()), this, SLOT(time_out()));

	m_timer.start(16.6675);
}

//ImageSequenceLabel::~ImageSequenceLabel()
//{
//	for (QPixmap image : m_image_seq)
//	{
//		if (image) delete image;
//		image = nullptr;
//	}
//
//	m_image_seq.clear();
//}

void ImageSequenceLabel::time_out()
{
	setPixmap(m_pixmaps.value(m_frame_number++).scaled(size()));

	if (m_frame_number == m_pixmaps.size()) m_frame_number = 0;

	m_timer.start(16.6675);
}
