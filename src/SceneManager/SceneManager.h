#pragma once
#include "Scene.h"
#include "SceneSerializer.h"

namespace TS_ENGINE
{
	class Scene;
	
	class SceneManager
	{
	public:
		static SceneManager* GetInstance();
		void SetCurrentScene(Ref<Scene> scene);

		void CreateNewScene(const std::string& sceneName);
		void SaveCurrentScene();
		void LoadScene(const std::string& savedScenePath);
		Ref<Scene> GetCurrentScene();

		void FlushCurrentScene();
	private:
		static SceneManager* mInstance;
		Ref<Scene> mCurrentScene;
		SceneManager();
		~SceneManager();

		Ref<SceneSerializer> mSceneSerializer;
		Ref<Node> GetCurrentSceneNode();
	};
}

