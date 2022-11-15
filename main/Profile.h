
class Profile
{
    typedef void (*FuncType)(char, KeyState);

private:
    const unsigned char *image;
    const char *name;
    const FuncType func;
    const bool release;

public:
    Profile(const unsigned char *image, const char *name, FuncType func, bool auto_release = true) : image(image), name(name), func(func), release(auto_release){};
    const unsigned char *GetImage() const
    {
        return image;
    }
    const char *GetName() const
    {
        return name;
    }
    bool Call(char c, KeyState state) const
    {
        (*func)(c, state);
        return release || (state == RELEASED);
    }
    ~Profile(){};
};
