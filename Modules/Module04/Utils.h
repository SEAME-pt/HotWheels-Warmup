#ifndef UTILS_H
#define UTILS_H

class Utils
{
public:
    // Template method for safe deletion of pointers
    template <typename T>
    static void safeDelete(T*& ptr) {
        if (ptr) {
            delete ptr;
            ptr = nullptr;
        }
    }
};

#endif // UTILS_H
