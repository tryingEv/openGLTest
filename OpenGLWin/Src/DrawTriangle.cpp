//
//  DrawTriagnle.cpp
//  ShaderTest
//
//  Created by hello tree on 2019/3/3.
//  Copyright © 2019 PlantTree. All rights reserved.
//

//#include "pch.h"
#include "DrawTriangle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
DrawTriangle::DrawTriangle():verticies(nullptr)
{
    
}

DrawTriangle:: ~DrawTriangle()
{
    
}

void DrawTriangle::init()
{
    //vertex shader
    const char* verty = "version 330 Core \n"
    "layout(location = 0) in vec3 aPos \n"
    "void main() \n"
    "{ \n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
    "}";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &verty, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        cout<<"compile vertex shader failed, the error is " << infoLog<<endl;
    }
    
    const char* fragmentShader = "version 330 Core \n"
    "out vec4 fragColor \n"
    "void main() \n"
    "{ \n"
    "   fragColor = vec4(1.0, 0.2, 0.5, 1); \n"
    "} \n";
    unsigned int fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragmentShader, NULL);
    glCompileShader(fragShader);
    int fragShaderCompileSuccess;
    char fragShaderCompileInfoLog[512];
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &fragShaderCompileSuccess);
    if(!fragShaderCompileSuccess)
    {
        glGetShaderInfoLog(fragShader, 512, NULL, fragShaderCompileInfoLog);
        cout<<"compile fragment shader failed, error: " << fragShaderCompileInfoLog<<endl;
    }
    
    
    /*unsigned int shaderPragam;*/
    shaderPragam = glCreateProgram();
    glAttachShader(shaderPragam, vertexShader);
    glAttachShader(shaderPragam, fragShader);
    glLinkProgram(shaderPragam);
    int linkShaderSuccess;
    char linkShaderInfoLog[512];
    glGetProgramiv(shaderPragam, GL_LINK_STATUS, &linkShaderSuccess);
    if(!linkShaderSuccess)
    {
        glGetProgramInfoLog(shaderPragam, 512, NULL, linkShaderInfoLog);
        cout<<"link shader failed, error:"<<linkShaderInfoLog<<endl;
    }
    
    glUseProgram(shaderPragam);
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
    
    
    
    float verticy[] =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    //    verticies = verticy;
    //unsigned int vbo;
	/*glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticy), verticy, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glUseProgram(shaderPragam);*/
	
	glBindVertexArray(VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticy), verticy, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void DrawTriangle::render()
{
	glUseProgram(shaderPragam);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void DrawTriangle::clear()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}


