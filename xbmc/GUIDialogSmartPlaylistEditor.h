#pragma once

/*
 *      Copyright (C) 2005-2008 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "GUIDialog.h"
#include "SmartPlaylist.h"

class CFileItemList;

class CGUIDialogSmartPlaylistEditor :
      public CGUIDialog
{
public:
  enum PLAYLIST_TYPE { TYPE_SONGS = 1, TYPE_ALBUMS, TYPE_MIXED, TYPE_MUSICVIDEOS, TYPE_MOVIES, TYPE_TVSHOWS, TYPE_EPISODES };

  CGUIDialogSmartPlaylistEditor(void);
  virtual ~CGUIDialogSmartPlaylistEditor(void);
  virtual bool OnMessage(CGUIMessage& message);
  virtual bool OnAction(const CAction &action);
  virtual void OnWindowLoaded();

  static bool EditPlaylist(const CStdString &path, const CStdString &type = "");
  static bool NewPlaylist(const CStdString &type);

protected:
  void OnRuleList(int item);
  void OnRuleAdd();
  void OnRuleRemove(int item);
  void OnName();
  void OnMatch();
  void OnLimit();
  void OnType();
  void OnOrder();
  void OnOrderDirection();
  void OnOK();
  void OnCancel();
  void UpdateButtons();
  int GetSelectedItem();
  void HighlightItem(int item);
  PLAYLIST_TYPE ConvertType(const CStdString &type);
  CStdString ConvertType(PLAYLIST_TYPE type);
  int GetLocalizedType(PLAYLIST_TYPE type);

  CSmartPlaylist m_playlist;

  // our list of rules for display purposes
  CFileItemList* m_ruleLabels;

  CStdString m_path;
  bool m_cancelled;
  CStdString m_mode;  // mode we're in (partymode etc.)
};
