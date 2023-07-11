#include "rich_label.h"
#include "app.h"
#include "draw_str.h"

#include "ctrl_def.h"

RichLabel::RichLabel(int w) : w(w) {
	gap = { 10, 10 };
	dep = 1000;
	txt = L"����ı�";
	fixed_w = true;
	c_txt = { 255, 255, 255 };
}
int RichLabel::GetW() const { return w + gap.x; }
int RichLabel::GetH() const { return h + gap.y; }

int RichLabel::w_line() const { return fixed_w ? w : 0; }
void RichLabel::render() {
	draw_str(scr, dscr, dep, txt, c_txt, ft, tl, w_line(), vp);
}
void RichLabel::Update() {
	Sync();
	dvec wh = str_wh(txt, ft, w_line());
	if (!fixed_w) { w = wh.x; }
	if (!fixed_h) { h = wh.y; }
	render();
}

RLbLan::RLbLan(int w, wstring const& id) : id(id), RichLabel(w) {}
void RLbLan::Sync() { txt = loc(id); }
