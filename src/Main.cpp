#include "stdafx.h"
#include "Tracer.h"

int main(int argc, char** argv)
{
  Magick::InitializeMagick(*argv);
  using namespace std;

  CTracer tracer;
  CScene scene;

  int xRes = 1024;  // Default resolution
  int yRes = 768;

  if (argc != 2 and argc != 3) {
    cerr << "Invalid command line! Exiting." << endl;
    return 1;
  }

  string configFilename = CONF_DIR "/config.txt";
  string outputFilename = argv[1];
  if (argc == 3)  // There is config file in parameters
  {
    configFilename = argv[1];
    outputFilename = argv[2];
  }

  ifstream file(configFilename);
  if (file)
  {
    int xResFromFile = 0;
    int yResFromFile = 0;
    if (file >> xResFromFile >> yResFromFile)
    {
      xRes = xResFromFile;
      yRes = yResFromFile;
    }
    else
      clog << "Invalid config format! Using default parameters." << endl;
  }
  else
    clog << "Invalid config path! Using default parameters." << endl;

  tracer.m_pScene = &scene;
  tracer.RenderImage(xRes, yRes);
  tracer.SaveImageToFile(outputFilename);
}
