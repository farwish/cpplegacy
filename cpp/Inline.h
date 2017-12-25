#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#endif

/**
 * 当类中成员函数包含 body 时，就代表他们是内联的。
 * 在声明外实现成员时，就需要额外加 inline。
 *
 * 使用场合：函数只有2~3行的，需要重复调用的
 * 不适合的：函数比较大，递归
 *
 * @license Apache-2.0
 * @author farwish <farwish@foxmail.com>
 */
class Rectangle {
    int width, height;

    public:
        Rectangle(int w, int h);

        void setWidth(int w);

        int getWidth() const;

        void setHeight(int h);

        int getHeight() const;
};

inline Rectangle::Rectangle(int w, int h) : width(w), height(h) {}

inline void Rectangle::setWidth(int w) {
    width = w; // or this->width = w;
}

inline int Rectangle::getWidth() const {
    return width;
}

inline void Rectangle::setHeight(int h) {
    height = h;
}

inline int Rectangle::getHeight() const {
    return height;
}
