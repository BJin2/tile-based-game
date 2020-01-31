#pragma once
#include <Windows.h>

class Grid;

class Game
{
private:
	HWND hWnd;
	Grid* grid;

	int resource;
	int max_scan;
	int max_extract;
	bool scanMode;

	RECT rect_text = { 0, 256, 256, 384 };

	int Extract(int x, int y);
	void Scan(int x, int y);
	void Mix();
	void RoundGrid(void(*passed)(int i, int j, Game* g), int x, int y, int thickness);
	LPWSTR text_chance;
	LPWSTR text_resource;
	LPWSTR text_message;
public:
	
	const unsigned short max_num_maxResource = 6;
	inline Grid* GetGrid() { return grid; }
	void SetOwner(HWND _hWnd);
	void Start();
	void Update();
	void UpdateText();
	void ScanMode();
	void ExtractMode();

	inline RECT* GetTextRect() { return &rect_text; }

	LPWSTR GetChanceText();
	int GetChanceTextLength();

	LPWSTR GetResourceText();
	int GetResourceTextLength();
	
	LPWSTR GetMessageText();
	int GetMessageTextLength();
};