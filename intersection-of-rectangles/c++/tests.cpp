const lest::test tests[] = {
    CASE("Overlap along both axes") {
        const Rectangle rect1(1, 1, 6, 3);
        const Rectangle rect2(5, 2, 3, 6);
        const Rectangle expected(5, 2, 2, 2);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
    CASE("One rectangle inside another") {
        const Rectangle rect1(1, 1, 6, 6);
        const Rectangle rect2(3, 3, 2, 2);
        const Rectangle expected(3, 3, 2, 2);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
    CASE("Both rectangles the same") {
        const Rectangle rect1(2, 2, 4, 4);
        const Rectangle rect2(2, 2, 4, 4);
        const Rectangle expected(2, 2, 4, 4);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
    CASE("Touch on horizontal edge") {
        const Rectangle rect1(1, 2, 3, 4);
        const Rectangle rect2(2, 6, 2, 2);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
    CASE("Touch on vertical edge") {
        const Rectangle rect1(1, 2, 3, 4);
        const Rectangle rect2(4, 3, 2, 2);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
    CASE("Touch at a corner") {
        const Rectangle rect1(1, 1, 2, 2);
        const Rectangle rect2(3, 3, 2, 2);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
    CASE("No overlap") {
        const Rectangle rect1(1, 1, 2, 2);
        const Rectangle rect2(4, 6, 3, 6);
        const Rectangle expected(0, 0, 0, 0);
        const Rectangle actual = findRectangularOverlap(rect1, rect2);
        EXPECT(actual == expected);
    },
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
