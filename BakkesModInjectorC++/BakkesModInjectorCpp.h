#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BakkesModInjectorCpp.h"
#include "WindowsUtils.h"
#include "DllInjector.h"
#include "qtimer.h"
#include "BakkesModInstallation.h"
#include "SettingsManager.h"
#include "Updater.h"
#include <qsystemtrayicon.h>


#define BAKKESMODINJECTOR_VERSION 5

enum BakkesModStatus
{
	BOOTING = 0,
	BAKKESMOD_IDLE = 1, //NO RL RUNNING
	WAITING_FOR_RL = 2,
	OUT_OF_DATE = 3,
	OUT_OF_DATE_SAFEMODE_ENABLED = 4,
	CHECKING_FOR_UPDATES = 5,
	START_UPDATING = 6,
	UPDATING_BAKKESMOD = 7,
	UPDATING_INJECTOR = 8,
	INJECT_DLL = 9,
	INJECTED = 10,
	INJECTION_FAILED = 11,
	BAKKESMOD_INSTALLING = 12,
	REINSTALL = 13,
	INSTALLATION_CORRUPT = 14
};

class BakkesModInjectorCpp : public QMainWindow
{
	Q_OBJECT
private:
	bool safeModeEnabled = false;
	BakkesModStatus bakkesModState = BOOTING;
	BakkesModInstallation installation;
	Updater updater;
	RegisterySettingsManager settingsManager;
	WindowsUtils windowsUtils;
	DllInjector dllInjector;
	QTimer timer;
	QSystemTrayIcon* trayIcon;
public:
	BakkesModInjectorCpp(QWidget *parent = Q_NULLPTR);
	void initialize();
	std::string GetStatusString();
	void changeEvent(QEvent* e);
	void OpenWebsite(std::string url);
public slots:
	void OnOpenBakkesModFolderClicked();
	void OnCheckInjection();
	void TimerTimeout();
	void OnCheckSafeMode();
	void OnMinimizeOnStart();
	void OnHideOnMinimize();
	void OnRunOnStartup();
	void OnExitClick();
	void OnReinstallClick();
	void OnPythonInstallClick();

	void OpenTwitter();
	void OpenDiscord();
	void OpenWebsite();
	void OpenTroubleshootPage();
	void trayClicked(QSystemTrayIcon::ActivationReason e);

private:
	Ui::BakkesModInjectorCppClass ui;
};
