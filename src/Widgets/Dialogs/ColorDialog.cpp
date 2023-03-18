#include "ColorDialog.h"

#include "Application.h"

#include <QRegularExpressionValidator>

using Layers::Attribute;
using Layers::ColorDialog;
using Layers::Themeable;

ColorDialog::ColorDialog(QWidget* parent) :
    Dialog("Color", parent)
{
    init_attributes();

    setFixedSize(315, 465);

    set_icon(new Graphic(":/svgs/color_icon.png"));
    set_name("color_dialog");
    set_proper_name("Color Dialog");

    m_apply_button->set_name("apply_button");
    m_apply_button->set_proper_name("Apply Button");
    //m_apply_button->set_padding(8, 6, 8, 6);
    m_apply_button->set_text_padding(1, 3, 0, 0);
    m_apply_button->disable_text_hover_color();
    connect(m_apply_button, &Button::clicked, [this] { done(QDialog::Accepted); });

    //m_z_slider->set_name("z_slider");

    //QRegularExpression rx("^#[0-9a-f]{3}([0-9a-f]{3})?$");

    m_color_name_line_editor->setFixedWidth(85);
    //m_color_name_line_editor->set_validator(new QRegularExpressionValidator(rx));

    connect(m_color_name_line_editor, &LineEditor::text_edited, [this] {
        qsizetype text_size = m_color_name_line_editor->text()->as<QString>().size();

        if (text_size == 6) // || text_size == 8)
            m_color->set_value(QColor("#" + m_color_name_line_editor->text()->as<QString>()));
        });

    m_color_plane->setFixedSize(160, 160);

    setup_layout();

    // Assign tag prefixes last!
    assign_tag_prefixes();

    // Set theme
    apply_theme(*layersApp->current_theme());
}

ColorDialog::~ColorDialog()
{
    delete m_color;

    m_color = nullptr;
}

Themeable* ColorDialog::clone()
{
    return new ColorDialog;
}

Attribute* ColorDialog::color() const
{
    return m_color;
}

void ColorDialog::update_color_name_line_editor()
{
    m_color_name_line_editor->set_text(
        m_color->as<QColor>().name().remove("#"));
}

void ColorDialog::init_attributes()
{
    m_color->entangle_with(m_color_plane->color);

    connect(m_color, &Attribute::value_changed,
        this, &ColorDialog::update_color_name_line_editor);

    m_z_slider->a_value.entangle_with(m_color_plane->z_value);
}

void ColorDialog::setup_layout()
{
    // Layout
    QVBoxLayout* layout = new QVBoxLayout;

    layout->setContentsMargins(7, 7, 7, 7);
    layout->setSpacing(12);
    layout->addWidget(m_color_plane);
    layout->addWidget(m_color_name_line_editor);
    layout->addWidget(m_z_slider);
    layout->addStretch();
    layout->addWidget(m_apply_button);
    layout->setAlignment(m_color_plane, Qt::AlignLeft);
    layout->setAlignment(m_apply_button, Qt::AlignRight);

    setLayout(layout);

    layout->activate();
}
