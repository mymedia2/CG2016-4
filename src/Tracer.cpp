#include "stdafx.h"
#include "Tracer.h"

using namespace glm;

SRay CTracer::MakeRay(glm::uvec2 pixelPos)
{
  return SRay();
}

glm::vec3 CTracer::TraceRay(SRay ray)
{
  vec3 color(0, 0, 1);
  return color;
}

void CTracer::RenderImage(int xRes, int yRes)
{
  // Rendering
  m_camera.m_resolution = uvec2(xRes, yRes);
  m_camera.m_pixels.resize(xRes * yRes);

  for (int i = 0; i < yRes; i++)
    for (int j = 0; j < xRes; j++)
    {
      SRay ray = MakeRay(uvec2(j, i));
      m_camera.m_pixels[i * xRes + j] = TraceRay(ray);
    }
}

#include <iostream>
void CTracer::SaveImageToFile(std::string fileName)
{
  int width = m_camera.m_resolution.x;
  int height = m_camera.m_resolution.y;

  using namespace Magick;
  Image image(Geometry(width, height), ColorRGB(0, 0, 0));
  image.modifyImage();
  PixelPacket* imageBuffer = image.getPixels(0, 0, width, height);

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      vec3 color = m_camera.m_pixels[i * width + j];

      ColorRGB c;
      c.red(clamp(color.r, 0.0f, 1.0f));
      c.green(clamp(color.g, 0.0f, 1.0f));
      c.blue(clamp(color.b, 0.0f, 1.0f));

      imageBuffer[i * width + j] = c;
    }
  }

  image.syncPixels();
  image.write(fileName);
}
