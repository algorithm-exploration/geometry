char * rectangleToString(const void *arg)
{
    const Rectangle *rect = arg;
    const size_t BUFFER_SIZE = 80;
    char *buffer = malloc(BUFFER_SIZE);

    assert(buffer != NULL);
    snprintf(buffer, BUFFER_SIZE, "(left: %d, bottom: %d, width: %d, height: %d)",
             rect->leftX, rect->bottomY, rect->width, rect->height);
    return buffer;
}

void overlapAlongBothAxesTest(Test *tc)
{
    const Rectangle rect1 = {1, 1, 6, 3};
    const Rectangle rect2 = {5, 2, 3, 6};
    const Rectangle expected = {5, 2, 2, 2};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

void oneRectangleInsideAnotherTest(Test *tc)
{
    const Rectangle rect1 = {1, 1, 6, 6};
    const Rectangle rect2 = {3, 3, 2, 2};
    const Rectangle expected = {3, 3, 2, 2};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

void bothRectanglesTheSameTest(Test *tc)
{
    const Rectangle rect1 = {2, 2, 4, 4};
    const Rectangle rect2 = {2, 2, 4, 4};
    const Rectangle expected = {2, 2, 4, 4};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

void touchOnHorizontalEdgeTest(Test *tc)
{
    const Rectangle rect1 = {1, 2, 3, 4};
    const Rectangle rect2 = {2, 6, 2, 2};
    const Rectangle expected = {0, 0, 0, 0};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

void touchOnVerticalEdgeTest(Test *tc)
{
    const Rectangle rect1 = {1, 2, 3, 4};
    const Rectangle rect2 = {4, 3, 2, 2};
    const Rectangle expected = {0, 0, 0, 0};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

void touchAtACornerTest(Test *tc)
{
    const Rectangle rect1 = {1, 1, 2, 2};
    const Rectangle rect2 = {3, 3, 2, 2};
    const Rectangle expected = {0, 0, 0, 0};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

void noOverlapTest(Test *tc)
{
    const Rectangle rect1 = {1, 1, 2, 2};
    const Rectangle rect2 = {4, 6, 3, 6};
    const Rectangle expected = {0, 0, 0, 0};
    const Rectangle actual = findRectangularOverlap(rect1, rect2);

    AssertStructEquals(tc, &expected, &actual, sizeof(expected), rectangleToString);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, overlapAlongBothAxesTest);
    SUITE_ADD_TEST(tests, oneRectangleInsideAnotherTest);
    SUITE_ADD_TEST(tests, bothRectanglesTheSameTest);
    SUITE_ADD_TEST(tests, touchOnHorizontalEdgeTest);
    SUITE_ADD_TEST(tests, touchOnVerticalEdgeTest);
    SUITE_ADD_TEST(tests, touchAtACornerTest);
    SUITE_ADD_TEST(tests, touchOnVerticalEdgeTest);
    SUITE_ADD_TEST(tests, touchAtACornerTest);
    SUITE_ADD_TEST(tests, noOverlapTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
