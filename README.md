# publiSH

publiSH is a small text editor written in C with GTK+ 3.

> **Status:** early prototype, not maintained. The interface is in place, but most features are not implemented yet.

## What it does (so far)

- Main window built with Glade: menu bar (File, Edit, View, Help), scrollable text area and a status bar
- Basic text editing, copy / cut / paste through the standard GTK text view
- Status bar message when copying to the clipboard
- File chooser dialog (opened from the *New* menu item for now)
- Work-in-progress undo stack, recording typed lines

Opening and saving files, undo/redo and most menu actions are not wired up yet.

## Project structure

```
core/                 Entry point, initialization, signal connections, shared structures
interface/
  glade/              UI definition (mainWindow.glade)
  textBuffer/         Text view events and undo stack
  menuItems/          Menu callbacks
  infoBar/            Status bar helper
Makefile
```

## Build

Requirements: `gcc`, `make`, and the GTK+ 3 development files (e.g. `libgtk-3-dev` on Debian/Ubuntu).

```sh
make
```

## Run

Run it from the root of the repository, since the UI file is loaded with a relative path:

```sh
./publiSH
```