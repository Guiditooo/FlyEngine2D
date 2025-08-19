#ifndef MATERIAL_SPEC_H
#define MATERIAL_SPEC_H

#include <Exports.h>
#include <glm.hpp>

namespace FlyEngine
{
    namespace Materials
    {
        enum class FLY_API MaterialList
        {
            Emerald,
            Jade,
            Obsidian,
            Pearl,
            Ruby,
            Turquoise,
            Brass,
            Bronze,
            Chrome,
            Copper,
            Gold,
            Silver,
            BlackPlastic,
            CyanPlastic,
            GreenPlastic,
            RedPlastic,
            WhitePlastic,
            YellowPlastic,
            BlackRubber,
            CyanRubber,
            GreenRubber,
            RedRubber,
            WhiteRubber,
            YellowRubber,
            AllAtOne,
            None
        };

        class FLY_API MaterialSpecification
        {
        private:
            glm::vec3 ambient;
            glm::vec3 diffuse;
            glm::vec3 specular;
            int ambientAmount;
            int diffuseAmount;
            int specularAmount;
            float shininess;
        public:
            MaterialSpecification(glm::vec3 amb, glm::vec3 diff, glm::vec3 spec, float shin);
            MaterialSpecification();
            ~MaterialSpecification();
            void SetSpecs(MaterialList material);

            glm::vec3 GetAmbient();
            glm::vec3 GetDiffuse();
            glm::vec3 GetSpecular();
            float GetShininess();
        };
    }
}

#endif // !MATERIAL_SPEC_H
