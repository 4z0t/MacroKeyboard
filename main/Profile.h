
typedef const unsigned char *const *IconGrid;

class Profile {
  typedef void (*FuncType)(char, KeyState);

private:
  const unsigned char *image;
  const char *name;
  const FuncType func;
  const IconGrid icons;
  const bool release;

public:
  Profile(const unsigned char *image, const char *name, FuncType func, const IconGrid icons = nullptr, bool auto_release = true)
    : image(image), name(name), func(func), icons(icons), release(auto_release){};
  const unsigned char *GetImage() const {
    return image;
  }
  const char *GetName() const {
    return name;
  }

  IconGrid GetIcons() const {
    return icons;
  }
  bool Call(char c, KeyState state) const {
    (*func)(c, state);
    return release || (state == RELEASED);
  }
  ~Profile(){};
};
