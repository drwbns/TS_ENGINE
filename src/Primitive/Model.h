#pragma once
#include "Core/tspch.h"
#include "Mesh.h"
#include "SceneManager/Node.h"

namespace TS_ENGINE {

	class Model
	{
	public:
		Model();
		Model(const std::string& modelPath);		
		~Model();		
		
		void LoadModel(const std::string& modelPath);
		//void ProcessEmbeddedTextures();
		void CopyFrom(Ref<Model> model);
		
		Ref<Node> GetRootNode() { return mRootNode; }
	private:
		Ref<Node> ProcessNode(aiNode* aiNode, const aiScene* scene);
		void AddMaterialToDictionary(Ref<Material> material);
		Ref<Mesh> ProcessMesh(aiMesh* aiMesh, const aiScene* scene);
		void ProcessTexture(aiMaterial* aiMat, Ref<TS_ENGINE::Material> tsMaterial, aiTextureType textureType, int numMaps);
		void ProcessMaterial(aiMaterial* aiMat);
	private:
		const aiScene* mAssimpScene;
		uint32_t mRendererID;
		AssimpMaterial mAssimpMaterial;
		Ref<Material> mMaterial;
		std::string mModelDirectory;
		Ref<Node> mRootNode;
		
		std::vector<Ref<Node>> mProcessedNodes = {};
		//std::vector<Ref<Mesh>> mProcessedMeshes = {};
		std::unordered_map<std::string, Ref<Material>> mProcessedMaterials = {};
		//std::unordered_map<std::string, Ref<Texture2D>> mProcessedEmbeddedTextures = {};
		Ref<Texture2D> mTexture;
	};
}

