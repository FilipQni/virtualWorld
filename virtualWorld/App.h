#pragma once
#include <wx/wx.h>
#include "World.h"

class App : public wxApp
{
public:
	World world;
	bool OnInit();
};