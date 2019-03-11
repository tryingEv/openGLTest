//
//  DrawTriagnle.hpp
//  ShaderTest
//
//  Created by hello tree on 2019/3/3.
//  Copyright © 2019 PlantTree. All rights reserved.
//

#ifndef DrawTriangle_hpp
#define DrawTriangle_hpp


using namespace std;
class DrawTriangle
{
public:
    float* verticies;
	unsigned int shaderPragam;
	unsigned int VBO, VAO;
    
    DrawTriangle();
    ~ DrawTriangle();
    void init();
	void render();
	void clear();
};

#endif /* DrawTriangle_hpp */
