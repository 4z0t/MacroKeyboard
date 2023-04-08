

#define LOGO_WIDTH 48
#define LOGO_HEIGHT 48

static const unsigned char PROGMEM git_logo[] = {
    0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0,
    0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00,
    0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00,
    0x00, 0x01, 0x07, 0xff, 0x80, 0x00, 0x00, 0x03, 0x83, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xc0, 0x3f,
    0xe0, 0x00, 0x00, 0x0f, 0xe0, 0x1f, 0xf0, 0x00, 0x00, 0x1f, 0xf0, 0x0f, 0xf8, 0x00, 0x00, 0x3f,
    0xf0, 0x0f, 0xfc, 0x00, 0x00, 0x7f, 0xf0, 0x0f, 0xfe, 0x00, 0x00, 0xff, 0xf0, 0x0f, 0xff, 0x00,
    0x01, 0xff, 0xf8, 0x07, 0xff, 0x80, 0x03, 0xff, 0xfc, 0x03, 0xff, 0xc0, 0x07, 0xff, 0xfc, 0x01,
    0xff, 0xe0, 0x0f, 0xff, 0xfc, 0x20, 0xff, 0xf0, 0x1f, 0xff, 0xfc, 0x30, 0x0f, 0xf8, 0x3f, 0xff,
    0xfc, 0x38, 0x07, 0xfc, 0x7f, 0xff, 0xfc, 0x3c, 0x03, 0xfe, 0xff, 0xff, 0xfc, 0x3c, 0x03, 0xff,
    0xff, 0xff, 0xfc, 0x3c, 0x03, 0xff, 0x7f, 0xff, 0xfc, 0x3c, 0x03, 0xfe, 0x3f, 0xff, 0xfc, 0x3e,
    0x03, 0xfc, 0x1f, 0xff, 0xfc, 0x3f, 0x07, 0xf8, 0x0f, 0xff, 0xfc, 0x3f, 0xff, 0xf0, 0x07, 0xff,
    0xfc, 0x3f, 0xff, 0xe0, 0x03, 0xff, 0xfc, 0x3f, 0xff, 0xc0, 0x01, 0xff, 0xf8, 0x1f, 0xff, 0x80,
    0x00, 0xff, 0xf0, 0x0f, 0xff, 0x00, 0x00, 0x7f, 0xf0, 0x0f, 0xfe, 0x00, 0x00, 0x3f, 0xf0, 0x0f,
    0xfc, 0x00, 0x00, 0x1f, 0xf0, 0x0f, 0xf8, 0x00, 0x00, 0x0f, 0xf8, 0x0f, 0xf0, 0x00, 0x00, 0x07,
    0xf8, 0x1f, 0xe0, 0x00, 0x00, 0x03, 0xfe, 0x7f, 0xc0, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00,
    0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc,
    0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00};

static const unsigned char PROGMEM msvs_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80,
    0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x0f,
    0xff, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00,
    0x00, 0x7f, 0xff, 0xc0, 0x07, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x0f, 0x80, 0x01, 0xff, 0xff, 0xc0,
    0x0f, 0xc0, 0x03, 0xff, 0xff, 0xc0, 0x0f, 0xf0, 0x07, 0xff, 0x7f, 0xc0, 0x0f, 0xf8, 0x0f, 0xfe,
    0x7f, 0xc0, 0x0f, 0xfc, 0x1f, 0xf8, 0x7f, 0xc0, 0x0f, 0x7f, 0x3f, 0xf0, 0x7f, 0xc0, 0x0f, 0x3f,
    0xff, 0xe0, 0x7f, 0xc0, 0x0f, 0x1f, 0xff, 0x80, 0x7f, 0xc0, 0x0f, 0x0f, 0xff, 0x00, 0x7f, 0xc0,
    0x0f, 0x0f, 0xff, 0x00, 0x7f, 0xc0, 0x0f, 0x1f, 0xff, 0x80, 0x7f, 0xc0, 0x0f, 0x3f, 0xff, 0xe0,
    0x7f, 0xc0, 0x0f, 0x7f, 0x3f, 0xf0, 0x7f, 0xc0, 0x0f, 0xfc, 0x1f, 0xf8, 0x7f, 0xc0, 0x0f, 0xf8,
    0x0f, 0xfe, 0x7f, 0xc0, 0x0f, 0xf0, 0x07, 0xff, 0x7f, 0xc0, 0x0f, 0xc0, 0x03, 0xff, 0xff, 0xc0,
    0x0f, 0x80, 0x01, 0xff, 0xff, 0xc0, 0x07, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x7f,
    0xff, 0xc0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00,
    0x00, 0x07, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const unsigned char PROGMEM vscode_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00,
    0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x1f,
    0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00,
    0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x60, 0x03, 0xff, 0xff, 0x80,
    0x00, 0xf0, 0x0f, 0xff, 0x7f, 0x80, 0x01, 0xf8, 0x1f, 0xfe, 0x7f, 0x80, 0x01, 0xfe, 0x3f, 0xf8,
    0x7f, 0x80, 0x01, 0xff, 0x7f, 0xf0, 0x7f, 0x80, 0x00, 0x7f, 0xff, 0xe0, 0x7f, 0x80, 0x00, 0x7f,
    0xff, 0xc0, 0x7f, 0x80, 0x00, 0x1f, 0xff, 0x00, 0x7f, 0x80, 0x00, 0x0f, 0xfe, 0x00, 0x7f, 0x80,
    0x00, 0x0f, 0xfe, 0x00, 0x7f, 0x80, 0x00, 0x1f, 0xff, 0x00, 0x7f, 0x80, 0x00, 0x7f, 0xff, 0x80,
    0x7f, 0x80, 0x00, 0xff, 0xff, 0xe0, 0x7f, 0x80, 0x01, 0xff, 0x7f, 0xf0, 0x7f, 0x80, 0x01, 0xfe,
    0x3f, 0xf8, 0x7f, 0x80, 0x01, 0xfc, 0x1f, 0xfe, 0x7f, 0x80, 0x00, 0xf0, 0x0f, 0xff, 0x7f, 0x80,
    0x00, 0x60, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00,
    0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const unsigned char PROGMEM unreal_engine_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0,
    0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x07,
    0xf0, 0x07, 0xf0, 0x00, 0x00, 0x0f, 0x80, 0x00, 0xf8, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x3c, 0x00,
    0x00, 0x78, 0x20, 0x00, 0x1f, 0x00, 0x00, 0xf0, 0xc0, 0x00, 0x07, 0x00, 0x01, 0xe3, 0xc0, 0x00,
    0x03, 0x80, 0x01, 0xc7, 0xc0, 0x00, 0x01, 0xc0, 0x03, 0x8f, 0x80, 0x00, 0x01, 0xe0, 0x07, 0x9f,
    0xc0, 0x00, 0xf0, 0xe0, 0x07, 0x1f, 0xc0, 0x03, 0xe0, 0x70, 0x0e, 0x3f, 0xc0, 0x3f, 0xc0, 0x70,
    0x0e, 0x7f, 0xf8, 0x1f, 0xc0, 0x38, 0x0e, 0x7f, 0xf8, 0x1f, 0xc0, 0x38, 0x1c, 0x7f, 0xf8, 0x1f,
    0xc0, 0x38, 0x1c, 0xff, 0xf8, 0x1f, 0xc0, 0x1c, 0x1c, 0xc3, 0xf8, 0x1f, 0xc0, 0x1c, 0x1c, 0xc1,
    0xf8, 0x1f, 0xc0, 0x1c, 0x18, 0x81, 0xf8, 0x1f, 0xc0, 0x1c, 0x18, 0x01, 0xf8, 0x1f, 0xc0, 0x1c,
    0x18, 0x01, 0xf8, 0x1f, 0xc0, 0x1c, 0x18, 0x01, 0xf8, 0x1f, 0xc0, 0x1c, 0x1c, 0x01, 0xf8, 0x1f,
    0xc0, 0x1c, 0x1c, 0x01, 0xf8, 0x1f, 0xc0, 0x1c, 0x1c, 0x01, 0xf8, 0x1f, 0xc1, 0x1c, 0x1c, 0x01,
    0xf8, 0x1f, 0xc1, 0x38, 0x0c, 0x01, 0xf8, 0x1f, 0xc3, 0x38, 0x0e, 0x01, 0xf8, 0x1f, 0xce, 0x38,
    0x0e, 0x01, 0xf8, 0x3f, 0xfe, 0x70, 0x07, 0x01, 0xfc, 0xff, 0xfc, 0x70, 0x07, 0x83, 0xff, 0xff,
    0xf8, 0xe0, 0x03, 0x8f, 0xff, 0xff, 0xf1, 0xe0, 0x01, 0xc7, 0xff, 0xff, 0xe1, 0xc0, 0x01, 0xe1,
    0xff, 0xe7, 0xc3, 0x80, 0x00, 0xf0, 0xff, 0xc3, 0x87, 0x00, 0x00, 0x78, 0x3f, 0x80, 0x0f, 0x00,
    0x00, 0x3e, 0x03, 0x00, 0x3c, 0x00, 0x00, 0x0f, 0x80, 0x00, 0xf8, 0x00, 0x00, 0x07, 0xe0, 0x07,
    0xf0, 0x00, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

static const unsigned char PROGMEM git_commit_icon[] = {
    0x00, 0x00, 0x30, 0x80, 0x49, 0x80, 0x49, 0xf8, 0x70, 0x8c, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04,
    0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x31, 0x0e, 0x1f, 0x92, 0x01, 0x92, 0x01, 0x0c, 0x00, 0x00};

#define ICON_SIZE 16

#define GRID3x3(name) static const unsigned char * const name[9]

GRID3x3(git_icons) = {
    nullptr, nullptr, git_commit_icon,
    nullptr, nullptr, nullptr,
    nullptr, nullptr, nullptr,
};
