# 1_FileStateBeholder
This is a QT 5.12.3 console app implementing QFileSystemWatcher-less file state tracking via a singleton FileMonitor class.

The FileMonitor contains a vector of FileState objects, each representing a unique file, possesses methods for adding and removing them, and a updateAndDisplayFileInfo() signal-method for displaying file state change for all added files since the method's last call or the files' addition; the FileState objects each encapsulate a single QFileInfo object, file existence info and modification date pulled from file system metadata during the last updateAndDisplayFileInfo() query, and possess appropriate getters.

updateAndDisplayFileInfo() displays following info per FileState object: the file was created/was deleted/was changed/exists unchanged since the last query; if the file currently exists - its reported size in bytes. The displayed state change is inferred from info from a previous query stored in the FileState object with it being overwritten with new, which it is compared with.
