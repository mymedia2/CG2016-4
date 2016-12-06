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

  for(int i = 0; i < yRes; i++)
    for(int j = 0; j < xRes; j++)
    {
      SRay ray = MakeRay(uvec2(j, i));
      m_camera.m_pixels[i * xRes + j] = TraceRay(ray);
    }
}

void CTracer::SaveImageToFile(std::string fileName)
{
  CImage image;

  int width = m_camera.m_resolution.x;
  int height = m_camera.m_resolution.y;

  image.Create(width, height, 24);
    
	int pitch = image.GetPitch();
	unsigned char* imageBuffer = (unsigned char*)image.GetBits();

	if (pitch < 0)
	{
		imageBuffer += pitch * (height - 1);
		pitch =- pitch;
	}

	int i, j;
	int imageDisplacement = 0;
	int textureDisplacement = 0;

	for (i = 0; i < height; i++)
	{
    for (j = 0; j < width; j++)
    {
      vec3 color = m_camera.m_pixels[textureDisplacement + j];

      imageBuffer[imageDisplacement + j * 3] = clamp(color.b, 0.0f, 1.0f) * 255.0f;
      imageBuffer[imageDisplacement + j * 3 + 1] = clamp(color.g, 0.0f, 1.0f) * 255.0f;
      imageBuffer[imageDisplacement + j * 3 + 2] = clamp(color.r, 0.0f, 1.0f) * 255.0f;
    }

		imageDisplacement += pitch;
		textureDisplacement += width;
	}

  image.Save(fileName.c_str());
	image.Destroy();
}

CImage* CTracer::LoadImageFromFile(std::string fileName)
{
  CImage* pImage = new CImage;

  if(SUCCEEDED(pImage->Load(fileName.c_str())))
    return pImage;
  else
  {
    delete pImage;
    return NULL;
  }
}
