/**

GDevelop - Tiled Sprite Extension
Copyright (c) 2012-2016 Victor Levasseur (victorlevasseur01@orange.fr)
Copyright (c) 2013-2016 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/
#ifndef TILEDSPRITEOBJECT_H
#define TILEDSPRITEOBJECT_H
#include <memory>

#include "GDCore/Project/ObjectConfiguration.h"
namespace gd {
class InitialInstance;
class Project;
}  // namespace gd

/**
 * TiledSprite Object
 */
class GD_EXTENSION_API TiledSpriteObject : public gd::ObjectConfiguration {
 public:
  TiledSpriteObject();
  virtual ~TiledSpriteObject(){};
  virtual std::unique_ptr<gd::ObjectConfiguration> Clone() const override {
    return gd::make_unique<TiledSpriteObject>(*this);
  }

  virtual void ExposeResources(gd::ArbitraryResourceWorker &worker) override;

  virtual std::map<gd::String, gd::PropertyDescriptor> GetProperties()
      const override;

  virtual bool UpdateProperty(const gd::String& name,
                              const gd::String& value) override;

  virtual double GetWidth() const { return width; };
  virtual double GetHeight() const { return height; };

  virtual void SetWidth(double newWidth) { width = newWidth; };
  virtual void SetHeight(double newHeight) { height = newHeight; };

  void SetTexture(const gd::String &newTextureName) {
    textureName = newTextureName;
  };
  const gd::String &GetTexture() const { return textureName; };

 private:
  virtual void DoUnserializeFrom(gd::Project &project,
                                 const gd::SerializerElement &element) override;
#if defined(GD_IDE_ONLY)
  virtual void DoSerializeTo(gd::SerializerElement &element) const override;
#endif

  gd::String textureName;
  double width;
  double height;
};

#endif  // TILEDSPRITEOBJECT_H
