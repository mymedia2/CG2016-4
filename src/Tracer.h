#pragma once
#include "stdafx.h"
#include "Types.h"
#include "Scene.h"

class CTracer
{
public:
  SRay MakeRay(glm::uvec2 pixelPos);  // Create ray for specified pixel
  glm::vec3 TraceRay(SRay ray); // Trace ray, compute its color
  void RenderImage(int xRes, int yRes);
  void SaveImageToFile(std::string fileName);

public:
  SCamera m_camera;
  CScene* m_pScene;
};
