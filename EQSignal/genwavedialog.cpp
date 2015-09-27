#include "genwavedialog.h"


GenWaveDialog::GenWaveDialog(QWidget *parent) : QDialog(parent)
{
    this->resize(400, 300);
    gridLayout = new QGridLayout(this);

    label_wavetype = new QLabel(tr("Wave Type"), this);
    label_N = new QLabel("N", this);
    label_dt = new QLabel("dt", this);
    label_A0 = new QLabel("A0", this);
    label_A = new QLabel("A", this);
    label_T = new QLabel("T", this);
    label_phi = new QLabel("phi", this);

    wavetype = new QComboBox(this);
    wavetype->addItem(tr("A0 + A*sin(2*pi/T*t + phi)"));
    N = new QSpinBox(this);
    N->setRange(128,65536);
    N->setValue(2048);
    dt = new QDoubleSpinBox(this);
    dt->setRange(0.001,0.1);
    dt->setValue(0.02);
    A0 = new QDoubleSpinBox(this);
    A = new QDoubleSpinBox(this);
    A->setValue(1.0);
    T = new QDoubleSpinBox(this);
    T->setValue(1.0);
    phi = new QDoubleSpinBox(this);

    gridLayout->addWidget(label_wavetype, 0, 0, 1, 1);
    gridLayout->addWidget(label_N, 1, 0, 1, 1);
    gridLayout->addWidget(label_dt, 2, 0, 1, 1);
    gridLayout->addWidget(label_A0, 3, 0, 1, 1);
    gridLayout->addWidget(label_A, 1, 2, 1, 1);
    gridLayout->addWidget(label_T, 2, 2, 1, 1);
    gridLayout->addWidget(label_phi, 3, 2, 1, 1);
    gridLayout->addWidget(wavetype, 0, 1, 1, 3);
    gridLayout->addWidget(N, 1, 1, 1, 1);
    gridLayout->addWidget(dt, 2, 1, 1, 1);
    gridLayout->addWidget(A0, 3, 1, 1, 1);
    gridLayout->addWidget(A, 1, 3, 1, 1);
    gridLayout->addWidget(T, 2, 3, 1, 1);
    gridLayout->addWidget(phi, 3, 3, 1, 1);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

    gridLayout->addWidget(buttonBox, 4, 0, 1, 4);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
