#define CPICLIB_EXPORTS
#include "ridge_detection.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static uint_t detect_row_mid(uint8_t* row, uint_t width)
{
    float threshold = 50.f;

    uint_t left_pixel = width;
    uint_t right_pixel = 0;

    for (uint_t i = 0; i < width; i++)
    {
        float px_contrast = row[i];

        if (px_contrast > threshold)
        {
            if (left_pixel > i)
            {
                left_pixel = i;
            }
            else
            {
                right_pixel = i;
            }
        }
    }

    if ((right_pixel - left_pixel) < 50)
    {
        return -1;
    }

    // printf("L: %u, R: %u \n", left_pixel, right_pixel);
    return (left_pixel + (right_pixel - left_pixel) / 2);
}


void detect_mid(
    uint8_t* image, uint_t width, uint_t height,
    uint_t samples,
    uint_t* out)
{
    if (samples == 0)
    {
        fprintf(stderr, "detect_mid called without samples!\n");
        return;
    }

    float nth_sample = height / (float)samples;

    for (uint_t i = 1; i < samples; i++)
    {
        uint_t line = ((uint_t)(nth_sample * i));
        out[i * 2] = line;
        out[i * 2 + 1] = detect_row_mid(image + line * width, width);
    }
}