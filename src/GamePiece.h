
#include <Engine.h>
#include "tweeny-3.2.0.h"

namespace MyChallengeGame
{
    using namespace Engine;

    class GamePiece
    {

        public:

        static const int DURATION  = 500;
        static const int STEP_MULT = 10;
        static const float ANIM_DELAY;
        
        GamePiece();
        GamePiece(Texture2D* texture, glm::vec2 position, glm::vec2 destination);
        ~GamePiece();

        void Update(float delta);

        void Draw(Spritebatch* spritebatch, float delta);

        void StartAnimation();

        void SetPosition(glm::vec2 pos);

        void SetPosition(float x, float y);

        glm::vec2 GetPosition() const { return m_Position; };

        void SetTween();

        float TweenProgress() const { return m_Tween.progress(); };

        void Reset();

        private:
        
        glm::vec2 m_InitialPosition;
        glm::vec2 m_Position;
        glm::vec2 m_Destination;
        tweeny::tween<float, float> m_Tween;
        Rectangle<int> m_ClipRect = {0, 0, 64, 64};
        Texture2D* m_Texture;
        float m_AnimationStarted = false;

        // timing
        float deltaAcumulation = 0;

    };


}
