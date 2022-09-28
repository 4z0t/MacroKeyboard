
class Profile
{
    typedef void (*FuncType)(char);

private:
    const unsigned char *image;
    const char *name;
    const FuncType func;

public:
    Profile(const unsigned char *image, const char *name, FuncType func) : image(image), name(name), func(func){};
    const unsigned char *GetImage() const
    {
        return image;
    }
    const char *GetName() const
    {
        return name;
    }
    void Call(char c) const
    {
        (*func)(c);
    }
    ~Profile(){};
};
