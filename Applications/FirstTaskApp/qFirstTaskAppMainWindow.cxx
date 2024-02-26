/*==============================================================================

  Copyright (c) Ebatinca, S.L.

==============================================================================*/

// FirstTask includes
#include "qFirstTaskAppMainWindow.h"
#include "qFirstTaskAppMainWindow_p.h"

// Qt includes
#include <QDesktopWidget>
#include <QLabel>

// Slicer includes
#include "qSlicerApplication.h"
#include "qSlicerAboutDialog.h"
#include "qSlicerMainWindow_p.h"
#include "qSlicerModuleSelectorToolBar.h"

//-----------------------------------------------------------------------------
// qFirstTaskAppMainWindowPrivate methods

qFirstTaskAppMainWindowPrivate::qFirstTaskAppMainWindowPrivate(qFirstTaskAppMainWindow& object)
  : Superclass(object)
{
}

//-----------------------------------------------------------------------------
qFirstTaskAppMainWindowPrivate::~qFirstTaskAppMainWindowPrivate()
{
}

//-----------------------------------------------------------------------------
void qFirstTaskAppMainWindowPrivate::init()
{
  Q_Q(qFirstTaskAppMainWindow);
  this->Superclass::init();
}

//-----------------------------------------------------------------------------
void qFirstTaskAppMainWindowPrivate::setupUi(QMainWindow * mainWindow)
{
  qSlicerApplication * app = qSlicerApplication::application();

  //----------------------------------------------------------------------------
  // Add actions
  //----------------------------------------------------------------------------
  QAction* helpAboutSlicerAppAction = new QAction(mainWindow);
  helpAboutSlicerAppAction->setObjectName("HelpAboutFirstTaskAppAction");
  helpAboutSlicerAppAction->setText("About " + app->applicationName());

  //----------------------------------------------------------------------------
  // Calling "setupUi()" after adding the actions above allows the call
  // to "QMetaObject::connectSlotsByName()" done in "setupUi()" to
  // successfully connect each slot with its corresponding action.
  this->Superclass::setupUi(mainWindow);

  //----------------------------------------------------------------------------
  // Configure
  //----------------------------------------------------------------------------
  mainWindow->setWindowIcon(QIcon(":/Icons/Medium/DesktopIcon.png"));

  QLabel* logoLabel = new QLabel();
  logoLabel->setObjectName("LogoLabel");
  // QIcon stores multiple versions of the image (in different sizes)
  // and uses the most suitable one (depending on DevicePixelRatio).
  // QLabel cannot take a QIcon, therefore we need to get the most suitable
  // QPixmap from the QIcon (base.png, base@2x, ...).
  // To achieve this, we first determine the pixmap size in device independent units,
  // which is the size of the base image (icon.availableSizes().first(), because for that
  // DevicePixelRatio=1.0), and then we retieve the pixmap for this size.
  QIcon icon = QIcon(":/LogoFull.png");
  QPixmap logo = icon.pixmap(icon.availableSizes().first());
  logoLabel->setPixmap(logo);

  // Hide the toolbars
  this->MainToolBar->setVisible(false);
  //this->ModuleSelectorToolBar->setVisible(false);
  this->ModuleToolBar->setVisible(false);
  this->ViewToolBar->setVisible(false);
  this->MouseModeToolBar->setVisible(false);
  this->CaptureToolBar->setVisible(false);
  this->ViewersToolBar->setVisible(false);
  this->DialogToolBar->setVisible(false);

  // Hide the menus
  //this->menubar->setVisible(false);
  //this->FileMenu->setVisible(false);
  //this->EditMenu->setVisible(false);
  //this->ViewMenu->setVisible(false);
  //this->LayoutMenu->setVisible(false);
  //this->HelpMenu->setVisible(false);

  // Hide the modules panel
  //this->PanelDockWidget->setVisible(false);
  this->DataProbeCollapsibleWidget->setCollapsed(true);
  this->DataProbeCollapsibleWidget->setVisible(false);
  this->StatusBar->setVisible(false);
}

//-----------------------------------------------------------------------------
// qFirstTaskAppMainWindow methods

//-----------------------------------------------------------------------------
qFirstTaskAppMainWindow::qFirstTaskAppMainWindow(QWidget* windowParent)
  : Superclass(new qFirstTaskAppMainWindowPrivate(*this), windowParent)
{
  Q_D(qFirstTaskAppMainWindow);
  d->init();
}

//-----------------------------------------------------------------------------
qFirstTaskAppMainWindow::qFirstTaskAppMainWindow(
  qFirstTaskAppMainWindowPrivate* pimpl, QWidget* windowParent)
  : Superclass(pimpl, windowParent)
{
  // init() is called by derived class.
}

//-----------------------------------------------------------------------------
qFirstTaskAppMainWindow::~qFirstTaskAppMainWindow()
{
}

//-----------------------------------------------------------------------------
void qFirstTaskAppMainWindow::on_HelpAboutFirstTaskAppAction_triggered()
{
  qSlicerAboutDialog about(this);
  about.setLogo(QPixmap(":/Logo.png"));
  about.exec();
}
