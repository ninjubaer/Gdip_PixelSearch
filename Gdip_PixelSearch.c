/*
 * Search Directions:
 * 0: Left to Right, Top to Bottom
 * 1: Right to Left, Top to Bottom
 * 2: Left to Right, Bottom to Top
 * 3: Right to Left, Bottom to Top
 */
int pixelsearch(unsigned int *haystack, unsigned int color, int w, int h, int stride, int *x, int *y, int variation, unsigned int sd)
{
    int i, j;
    if (sd == 0)
    {
        if (!variation)
        {
            for (j = *y; j < h; j++)
            {
                for (i = *x; i < w; i++)
                {
                    if (haystack[j * stride / 4 + i] == color)
                    {
                        *x = i, *y = j;
                        return 1;
                    }
                }
            }
            *x = -1, *y = -1;
            return 0;
        }
        int a, r, g, b, a2, r2, g2, b2;
        a = (color & 0xFF000000) >> 24;
        r = (color & 0x00FF0000) >> 16;
        g = (color & 0x0000FF00) >> 8;
        b = (color & 0x000000FF);

        for (j = *y; j < h; j++)
        {
            for (i = *x; i < w; i++)
            {
                if (haystack[j * stride / 4 + i] == color)
                {
                    *x = i, *y = j;
                    return 1;
                }
                a2 = (haystack[j * stride / 4 + i] & 0xFF000000) >> 24;
                r2 = (haystack[j * stride / 4 + i] & 0x00FF0000) >> 16;
                g2 = (haystack[j * stride / 4 + i] & 0x0000FF00) >> 8;
                b2 = (haystack[j * stride / 4 + i] & 0x000000FF);

                if ((r2 >= r - variation && r2 <= r + variation) &&
                    (g2 >= g - variation && g2 <= g + variation) &&
                    (b2 >= b - variation && b2 <= b + variation) &&
                    (a2 >= a - variation && a2 <= a + variation))
                {
                    *x = i, *y = j;
                    return 1;
                }
            }
        }
        *x = -1, *y = -1;
        return 0;
    }
    else if (sd == 1)
    {
        if (!variation)
        {
            for (j = *y; j < h; j++)
            {
                for (i = w-1; i >= *x; i--)
                {
                    if (haystack[j * stride / 4 + i] == color)
                    {
                        *x = i, *y = j;
                        return 1;
                    }
                }
            }
            *x = -1, *y = -1;
            return 0;
        }
        int a, r, g, b, a2, r2, g2, b2;
        a = (color & 0xFF000000) >> 24;
        r = (color & 0x00FF0000) >> 16;
        g = (color & 0x0000FF00) >> 8;
        b = (color & 0x000000FF);

        for (j = *y; j < h; j++)
        {
            for (i = w-1; i >= *x; i--)
            {
                if (haystack[j * stride / 4 + i] == color)
                {
                    *x = i, *y = j;
                    return 1;
                }
                a2 = (haystack[j * stride / 4 + i] & 0xFF000000) >> 24;
                r2 = (haystack[j * stride / 4 + i] & 0x00FF0000) >> 16;
                g2 = (haystack[j * stride / 4 + i] & 0x0000FF00) >> 8;
                b2 = (haystack[j * stride / 4 + i] & 0x000000FF);

                if ((r2 >= r - variation && r2 <= r + variation) &&
                    (g2 >= g - variation && g2 <= g + variation) &&
                    (b2 >= b - variation && b2 <= b + variation) &&
                    (a2 >= a - variation && a2 <= a + variation))
                {
                    *x = i, *y = j;
                    return 1;
                }
            }
        }
        *x = -1, *y = -1;
        return 0;
    }
    else if (sd == 2)
    {
        if (!variation)
        {
            for (j = h-1; j >= *y; j--)
            {
                for (i = *x; i < w; i++)
                {
                    if (haystack[j * stride / 4 + i] == color)
                    {
                        *x = i, *y = j;
                        return 1;
                    }
                }
            }
            *x = -1, *y = -1;
            return 0;
        }
        int a, r, g, b, a2, r2, g2, b2;
        a = (color & 0xFF000000) >> 24;
        r = (color & 0x00FF0000) >> 16;
        g = (color & 0x0000FF00) >> 8;
        b = (color & 0x000000FF);

        for (j = h-1; j >= *y; j--)
        {
            for (i = *x; i < w; i++)
            {
                if (haystack[j * stride / 4 + i] == color)
                {
                    *x = i, *y = j;
                    return 1;
                }
                a2 = (haystack[j * stride / 4 + i] & 0xFF000000) >> 24;
                r2 = (haystack[j * stride / 4 + i] & 0x00FF0000) >> 16;
                g2 = (haystack[j * stride / 4 + i] & 0x0000FF00) >> 8;
                b2 = (haystack[j * stride / 4 + i] & 0x000000FF);

                if ((r2 >= r - variation && r2 <= r + variation) &&
                    (g2 >= g - variation && g2 <= g + variation) &&
                    (b2 >= b - variation && b2 <= b + variation) &&
                    (a2 >= a - variation && a2 <= a + variation))
                {
                    *x = i, *y = j;
                    return 1;
                }
            }
        }
        *x = -1, *y = -1;
        return 0;
    }
    else if (sd == 3)
    {
        if (!variation)
        {
            for (j = h-1; j >= *y; j--)
            {
                for (i = w-1; i >= *x; i--)
                {
                    if (haystack[j * stride / 4 + i] == color)
                    {
                        *x = i, *y = j;
                        return 1;
                    }
                }
            }
            *x = -1, *y = -1;
            return 0;
        }
        int a, r, g, b, a2, r2, g2, b2;
        a = (color & 0xFF000000) >> 24;
        r = (color & 0x00FF0000) >> 16;
        g = (color & 0x0000FF00) >> 8;
        b = (color & 0x000000FF);

        for (j = h-1; j >= *y; j--)
        {
            for (i = w-1; i >= *x; i--)
            {
                if (haystack[j * stride / 4 + i] == color)
                {
                    *x = i, *y = j;
                    return 1;
                }
                a2 = (haystack[j * stride / 4 + i] & 0xFF000000) >> 24;
                r2 = (haystack[j * stride / 4 + i] & 0x00FF0000) >> 16;
                g2 = (haystack[j * stride / 4 + i] & 0x0000FF00) >> 8;
                b2 = (haystack[j * stride / 4 + i] & 0x000000FF);

                if ((r2 >= r - variation && r2 <= r + variation) &&
                    (g2 >= g - variation && g2 <= g + variation) &&
                    (b2 >= b - variation && b2 <= b + variation) &&
                    (a2 >= a - variation && a2 <= a + variation))
                {
                    *x = i, *y = j;
                    return 1;
                }
            }
        }
        *x = -1, *y = -1;
        return 0;
    }
    return -1;
}
