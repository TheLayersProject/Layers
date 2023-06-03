#include "SettingsTab.h"

#include "Graphic.h"
#include "Label.h"

#include <QIntValidator>
#include <QMouseEvent>

using Layers::Graphic;
using Layers::SettingsTab;

SettingsTab::SettingsTab(const Graphic& icon, const QString& label_text, QWidget* parent) :
	m_icon_label{ new Label(icon) }, m_text_label { new Label(label_text) }, Widget(parent)
{
    init_attributes();

	connect(this, &SettingsTab::clicked, [this] { if (state() != "Selected") set_state("Selected"); });

    installEventFilter(this);
    setMouseTracking(true);
	setFixedHeight(60);

    set_icon(Graphic(":/svgs/settings_tab_icon.svg", QSize(20, 9)));
    set_name("Setting Tab");

    m_icon_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_icon_label->set_icon(icon);
	m_icon_label->set_name("Icon Label");

    m_text_label->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_text_label->set_name("Text Label");
    m_text_label->set_font_size(14);

    init_layout();

    set_state("Unselected");
}

void SettingsTab::init_attributes()
{
    m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
    m_fill->init_variant_map({
        { "Unselected", QColor(Qt::lightGray) },
        { "Selected", QColor(Qt::white) }
        });

    m_icon_label->graphic()->svg_renderer()->common_color()->init_variant_map({
		{ "Unselected", QColor(Qt::gray) },
		{ "Selected", QColor(Qt::black) }
		});

	m_text_label->text_color()->init_variant_map({
		{ "Unselected", QColor(Qt::gray) },
		{ "Selected", QColor(Qt::black) }
		});
}

int SettingsTab::recommended_minimum_width()
{
    return 18 + m_icon_label->sizeHint().width() + 12 + m_text_label->sizeHint().width() + 18;
}

void SettingsTab::set_disabled(bool cond)
{
    m_disabled = cond;
}

bool SettingsTab::eventFilter(QObject* object, QEvent* event)
{
    if (!m_disabled)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

            if (mouse_event->button() & Qt::LeftButton)
            {
                emit clicked();
            }
        }
    }

    return false;
}

void SettingsTab::resizeEvent(QResizeEvent* event)
{
    int minimum_width = 18 + m_icon_label->width() + 12 + m_text_label->width() + 18;

    if (width() < minimum_width)
        emit under_minimum_width();
    else
        emit over_minimum_width();
}

void SettingsTab::init_layout()
{
    main_layout->setContentsMargins(18, 0, 18, 0);
    main_layout->setSpacing(12);
    main_layout->addWidget(m_icon_label);
    main_layout->addWidget(m_text_label);

    setLayout(main_layout);
}
