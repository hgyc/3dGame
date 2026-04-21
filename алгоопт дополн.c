//#define GLAD_GLAPI_EXPORT
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <time.h>
//#include <math.h>
//#include <cglm/cglm.h>
//#include <string.h>
//
//#define STB_EASY_FONT_IMPLEMENTATION
//#include "stb_easy_font.h"
//
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//
//// =============== PROFILING CONFIG ===============
//#define PROFILING_MODE 1  // 1 = включить профилирование
//// ================================================
//
//#define BULLETTIME 0.70
//#define BULLETSPEED 0.01f
//#define MAX_BULLETS 100
//#define MAX_ENEMIES 30
//
//#define ENEMY_SIZEX 0.1f
//#define ENEMY_SIZEY 0.1f
//#define ENEMY_SIZEZ 0.05f
//#define ENEMY_SPEED 0.002f
//#define SCREEN_LIMIT_X 0.9f
//#define PLAYER_HITS_TO_DIE 10
//#define FORMATION_ROWS 3
//#define FORMATION_COLS 9
//#define H_SPACING 0.15f
//#define V_SPACING 0.2f
//#define DIVE_INTERVAL 7
//#define DIVE_SPEED 0.002f
//#define DIVE_ACCEL 0.00005f
//#define PLAYER_COLLIDE_RX 0.05f
//#define PLAYER_COLLIDE_RY 0.05f
//#define STARTPLY -0.4f
//#define MAX_SCORES 10
//
//// === Шейдеры ===
//const char* instancedBulletVertexShader =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColour;\n"
//"layout (location = 2) in vec3 instanceOffset;\n"
//"uniform mat4 model;\n"
//"uniform mat4 view;\n"
//"uniform mat4 projection;\n"
//"out vec3 colour;\n"
//"void main()\n"
//"{\n"
//"    vec3 pos = aPos + instanceOffset;\n"
//"    gl_Position = projection * view * model * vec4(pos, 1.0);\n"
//"    colour = aColour;\n"
//"}\n";
//
//const char* bulletFragmentShader =
//"#version 330 core\n"
//"in vec3 colour;\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"    FragColor = vec4(colour, 1.0f);\n"
//"}\n";
//
//const char* primvetexshader =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec2 aTexcoords;\n"
//"out vec2 Texcoords;\n"
//"void main()\n"
//"{\n"
//"    gl_Position = vec4(aPos, 1.0);\n"
//"    Texcoords = aTexcoords;\n"
//"}\n";
//
//const char* primefragmentshader =
//"#version 330 core\n"
//"in vec2 Texcoords;\n"
//"out vec4 FragColor;\n"
//"uniform sampler2D texture1;\n"
//"void main()\n"
//"{\n"
//"FragColor = texture(texture1, Texcoords);\n"
//"}\n";
//
//const char* instancedEnemyVertexShader =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec2 aTexCoords;\n"
//"layout (location = 2) in vec3 aNormal;\n"
//"layout (location = 3) in vec3 instanceOffset;\n"
//"layout (location = 4) in int instanceIsHit;\n"
//"uniform mat4 model;\n"
//"uniform mat4 view;\n"
//"uniform mat4 projection;\n"
//"out vec2 TexCoords;\n"
//"out vec3 Normal;\n"
//"out vec3 FragPos;\n"
//"flat out int isHit;\n"
//"void main()\n"
//"{\n"
//"    vec3 worldPos = aPos + instanceOffset;\n"
//"    FragPos = vec3(model * vec4(worldPos, 1.0));\n"
//"    Normal = mat3(transpose(inverse(model))) * aNormal;\n"
//"    TexCoords = aTexCoords;\n"
//"    isHit = instanceIsHit;\n"
//"    gl_Position = projection * view * vec4(FragPos, 1.0);\n"
//"}\n";
//
//const char* instancedEnemyFragmentShader =
//"#version 330 core\n"
//"in vec2 TexCoords;\n"
//"in vec3 Normal;\n"
//"in vec3 FragPos;\n"
//"flat in int isHit;\n"
//"out vec4 FragColor;\n"
//"uniform sampler2D texture1;\n"
//"void main()\n"
//"{\n"
//"    if (isHit == 1)\n"
//"        FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
//"    else\n"
//"        FragColor = texture(texture1, TexCoords);\n"
//"}\n";
//
//const char* textVertexSrc =
//"#version 330 core\n"
//"layout(location = 0) in vec4 vertex; // <vec2 pos, vec2 tex>\n"
//"out vec2 TexCoords;\n"
//"void main()\n"
//"{\n"
//"    gl_Position = vec4(vertex.xy, 0.0, 1.0);\n"
//"    TexCoords = vertex.zw;\n"
//"}\n";
//
//const char* textFragmentSrc =
//"#version 330 core\n"
//"in vec2 TexCoords;\n"
//"out vec4 FragColor;\n"
//"uniform sampler2D font;\n"
//"void main()\n"
//"{\n"
//"    float alpha = texture(font, TexCoords).r;\n"
//"    FragColor = vec4(1.0, 1.0, 1.0, alpha);\n"
//"}\n";
//
//// ========== ШЕЙДЕРЫ ДЛЯ ИГРОКА (исправлено) ==========
//const char* modelvertexShaderSource =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec2 aTexCoords;\n"
//"layout (location = 2) in vec3 aNormal;\n"
//"uniform vec3 offset;\n"
//"uniform mat4 model;\n"
//"uniform mat4 view;\n"
//"uniform mat4 projection;\n"
//"out vec2 TexCoords;\n"
//"out vec3 Normal;\n"
//"out vec3 FragPos;\n"
//"void main()\n"
//"{\n"
//"    vec3 worldPos = aPos + offset;\n"
//"    FragPos = vec3(model * vec4(worldPos, 1.0));\n"
//"    Normal = mat3(transpose(inverse(model))) * aNormal;\n"
//"    TexCoords = aTexCoords;\n"
//"    gl_Position = projection * view * vec4(FragPos, 1.0);\n"
//"}\n";
//
//const char* modelfragmentShaderSource =
//"#version 330 core\n"
//"in vec2 TexCoords;\n"
//"in vec3 Normal;\n"
//"in vec3 FragPos;\n"
//"out vec4 FragColor;\n"
//"uniform sampler2D texture1;\n"
//"uniform int isHit;\n"
//"void main()\n"
//"{\n"
//"    if (isHit == 1)\n"
//"        FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
//"    else\n"
//"        FragColor = texture(texture1, TexCoords);\n"
//"}\n";
//// ===================================================
//
//float last_timebul = 0, last_enemy_shot = 0, lastDiveTime = 0;
//float enemyShotInterval = 2.0f;
//int score = 0, wave = 0, baseEnemyScore = 50, baseWaveScore = 1000;
//float diveIntervalVar = DIVE_INTERVAL;
//int playerHits = 0, kills = 0, playerIsHit = 0;
//unsigned int VAO_text, VBO_text;
//unsigned int menuShader, textShader;
//unsigned int fontTexture;
//int highscores[MAX_SCORES] = { 0 };
//long long int draw_call_count = 0;
//
//// ========== DOUBLE BUFFERING STRUCTURES ==========
//typedef struct {
//    GLuint buffers[2];
//    int currentBuffer;
//    float* mappedData;
//    GLsync fences[2];
//} DoubleBuffer;
//
//DoubleBuffer bulletDoubleBuffer;
//DoubleBuffer enemyDoubleBuffer;
//// ================================================
//
//typedef struct {
//    unsigned int vertexIndex;
//    unsigned int uvIndex;
//    unsigned int normalIndex;
//} Face;
//
//typedef struct {
//    vec3* vertices;
//    vec2* texCoords;
//    vec3* normals;
//    Face* faces;
//    unsigned int numVertices;
//    unsigned int numTexCoords;
//    unsigned int numNormals;
//    unsigned int numFaces;
//} Model;
//
//typedef struct Bullets {
//    float x, y;
//    char active;
//    char dir;
//} Bullet;
//
//typedef struct {
//    float x, y, speedX, speedY;
//    int lives;
//    char active, diving, hit;
//} Enemy;
//
//typedef enum {
//    STATE_MENU,
//    STATE_PLAYING,
//    STATE_CONTROLS,
//    STATE_HIGHSCORES
//} GameState;
//
//GameState gameState;
//
//Bullet bullets[MAX_BULLETS] = { 0 };
//int bulletCount = 0;
//
//Enemy enemies[MAX_ENEMIES];
//
//// === Глобальные для инстансинга ===
//unsigned int bulletShader;
//unsigned int VAO_b, VBO_b;
//
//unsigned int enemyShader;
//unsigned int enemyVAO, enemyVBO;
//Model enemymodel;
//
//// Для игрока
//unsigned int playerShader;
//unsigned int playerVAO, playerVBO;
//Model playermodel;
//
//// ========== DOUBLE BUFFERING FUNCTIONS ==========
//void initDoubleBuffer(DoubleBuffer* db, GLsizeiptr size) {
//    glGenBuffers(2, db->buffers);
//    for (int i = 0; i < 2; i++) {
//        glBindBuffer(GL_ARRAY_BUFFER, db->buffers[i]);
//        glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_STREAM_DRAW);
//        db->fences[i] = 0;
//    }
//    db->currentBuffer = 0;
//    db->mappedData = NULL;
//}
//
//void beginDoubleBufferUpdate(DoubleBuffer* db) {
//    // Ждем, пока предыдущий фрейм закончит использовать этот буфер
//    if (db->fences[db->currentBuffer]) {
//        glClientWaitSync(db->fences[db->currentBuffer], 0, GL_TIMEOUT_IGNORED);
//        glDeleteSync(db->fences[db->currentBuffer]);
//    }
//
//    glBindBuffer(GL_ARRAY_BUFFER, db->buffers[db->currentBuffer]);
//    db->mappedData = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
//}
//
//void endDoubleBufferUpdate(DoubleBuffer* db) {
//    if (db->mappedData) {
//        glUnmapBuffer(GL_ARRAY_BUFFER);
//        db->mappedData = NULL;
//    }
//
//    // Устанавливаем fence для синхронизации
//    db->fences[db->currentBuffer] = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
//
//    // Переключаемся на следующий буфер
//    db->currentBuffer = (db->currentBuffer + 1) % 2;
//}
//
//void cleanupDoubleBuffer(DoubleBuffer* db) {
//    for (int i = 0; i < 2; i++) {
//        if (db->fences[i]) {
//            glDeleteSync(db->fences[i]);
//        }
//    }
//    glDeleteBuffers(2, db->buffers);
//}
//// ================================================
//
//void checkShaderCompileErrors(unsigned int shader)
//{
//    int success;
//    char infoLog[512];
//    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(shader, 512, NULL, infoLog);
//        printf("ERROR::SHADER::COMPILATION_FAILED\n%s\n", infoLog);
//    }
//}
//
//void shootBullet(float px)
//{
//    if ((glfwGetTime() - last_timebul) > 0.13 && bulletCount < MAX_BULLETS)
//    {
//        for (int i = 0; i < MAX_BULLETS; i++) {
//            if (!bullets[i].active) {
//                bullets[i].x = px;
//                bullets[i].y = STARTPLY + ENEMY_SIZEY;
//                bullets[i].dir = 1;
//                bullets[i].active = 1;
//                bulletCount++;
//                last_timebul = glfwGetTime();
//                break;
//            }
//        }
//    }
//}
//
//void updateBullets()
//{
//    for (int i = 0; i < MAX_BULLETS; i++) {
//        if (!bullets[i].active) continue;
//        bullets[i].y += BULLETSPEED * bullets[i].dir;
//        if (fabsf(bullets[i].y) > 1.0f) {
//            bullets[i].active = 0;
//            bulletCount--;
//        }
//    }
//}
//
//void drawBullets(mat4 model, mat4 view, mat4 projection)
//{
//    int instanceCount = 0;
//
//    beginDoubleBufferUpdate(&bulletDoubleBuffer);
//    float* offsets = bulletDoubleBuffer.mappedData;
//
//    for (int i = 0; i < MAX_BULLETS; i++) {
//        if (bullets[i].active) {
//            offsets[instanceCount * 3 + 0] = bullets[i].x;
//            offsets[instanceCount * 3 + 1] = bullets[i].y;
//            offsets[instanceCount * 3 + 2] = 0.0f;
//            instanceCount++;
//        }
//    }
//
//    endDoubleBufferUpdate(&bulletDoubleBuffer);
//
//    if (instanceCount == 0) return;
//
//    // Используем предыдущий буфер (который уже готов)
//    int renderBuffer = (bulletDoubleBuffer.currentBuffer + 1) % 2;
//    glBindBuffer(GL_ARRAY_BUFFER, bulletDoubleBuffer.buffers[renderBuffer]);
//
//    glUseProgram(bulletShader);
//    glUniformMatrix4fv(glGetUniformLocation(bulletShader, "model"), 1, GL_FALSE, &model[0][0]);
//    glUniformMatrix4fv(glGetUniformLocation(bulletShader, "view"), 1, GL_FALSE, &view[0][0]);
//    glUniformMatrix4fv(glGetUniformLocation(bulletShader, "projection"), 1, GL_FALSE, &projection[0][0]);
//
//    glBindVertexArray(VAO_b);
//    draw_call_count++;
//    glDrawArraysInstanced(GL_TRIANGLES, 0, 6, instanceCount);
//    glBindVertexArray(0);
//}
//
//void shootEnemyBullet(float ex, float ey, float interval)
//{
//    if ((glfwGetTime() - last_enemy_shot) > interval && bulletCount < MAX_BULLETS)
//    {
//        for (int i = 0; i < MAX_BULLETS; i++) {
//            if (!bullets[i].active) {
//                bullets[i].x = ex;
//                bullets[i].y = ey;
//                bullets[i].dir = -1;
//                bullets[i].active = 1;
//                bulletCount++;
//                last_enemy_shot = glfwGetTime();
//                break;
//            }
//        }
//    }
//}
//
//void updateEnemy()
//{
//    for (int j = 0; j < MAX_ENEMIES; j++) {
//        if (!enemies[j].active) continue;
//        for (int i = 0; i < MAX_BULLETS; i++) {
//            if (!bullets[i].active || bullets[i].dir != 1) continue;
//            if ((fabs(bullets[i].x - enemies[j].x) <= ENEMY_SIZEX) &&
//                (fabs(bullets[i].y - enemies[j].y) <= ENEMY_SIZEY)) {
//                enemies[j].lives--;
//                bullets[i].active = 0;
//                bulletCount--;
//                enemies[j].hit = 1;
//                if (enemies[j].lives == 0) {
//                    enemies[j].active = 0;
//                    kills++;
//                    score += baseEnemyScore + 5 * wave;
//                }
//            }
//        }
//    }
//}
//
//void spawnFormation()
//{
//    for (int r = 0; r < FORMATION_ROWS; r++)
//        for (int c = 0; c < FORMATION_COLS; c++)
//        {
//            int i = r * FORMATION_COLS + c;
//            enemies[i].x = -H_SPACING * (FORMATION_COLS - 1) / 2 + c * H_SPACING;
//            enemies[i].y = 0.8f - r * V_SPACING;
//            enemies[i].speedX = ENEMY_SPEED;
//            enemies[i].speedY = 0.0f;
//            enemies[i].lives = 4 + 2 * wave;
//            enemies[i].active = 1;
//            enemies[i].diving = 0;
//            enemies[i].hit = 0;
//        }
//}
//
//void updateEnemyMovement(float playerX)
//{
//    for (int j = 0; j < MAX_ENEMIES; j++)
//    {
//        if (enemies[j].active && !enemies[j].diving)
//        {
//            if (enemies[j].x + ENEMY_SIZEX >= SCREEN_LIMIT_X ||
//                enemies[j].x - ENEMY_SIZEX <= -SCREEN_LIMIT_X)
//            {
//                for (int k = 0; k < MAX_ENEMIES; k++)
//                {
//                    if (enemies[k].active && !enemies[k].diving)
//                    {
//                        enemies[k].speedX = -enemies[k].speedX;
//                    }
//                }
//                break;
//            }
//        }
//    }
//
//    for (int i = 0; i < MAX_ENEMIES; i++)
//    {
//        if (!enemies[i].active)
//            continue;
//
//        if (enemies[i].diving)
//        {
//            float dx = playerX - enemies[i].x;
//            float dy = STARTPLY - enemies[i].y;
//            float dist = sqrtf(dx * dx + dy * dy);
//            if (dist > 0.0f)
//            {
//                dx /= dist;
//                dy /= dist;
//                enemies[i].speedX += DIVE_ACCEL * dx;
//                enemies[i].speedY += DIVE_ACCEL * dy;
//            }
//            enemies[i].x += enemies[i].speedX;
//            enemies[i].y += enemies[i].speedY;
//
//            if (enemies[i].y < STARTPLY - 0.5f ||
//                enemies[i].x < -1.0f || enemies[i].x > 1.0f)
//            {
//                float deltaX = 0.0f;
//                float repInitX = 0.0f;
//                float repSpeed = ENEMY_SPEED;
//                for (int k = 0; k < MAX_ENEMIES; k++)
//                {
//                    if (enemies[k].active && !enemies[k].diving)
//                    {
//                        int c = k % FORMATION_COLS;
//                        repInitX = -H_SPACING * (FORMATION_COLS - 1) / 2 + c * H_SPACING;
//                        deltaX = enemies[k].x - repInitX;
//                        repSpeed = enemies[k].speedX;
//                        break;
//                    }
//                }
//
//                int r = i / FORMATION_COLS, c = i % FORMATION_COLS;
//                float initX = -H_SPACING * (FORMATION_COLS - 1) / 2 + c * H_SPACING;
//                enemies[i].x = initX + deltaX;
//                enemies[i].y = 0.8f - r * V_SPACING;
//                enemies[i].speedX = repSpeed;
//                enemies[i].speedY = 0.0f;
//                enemies[i].diving = 0;
//            }
//        }
//        else
//        {
//            enemies[i].x += enemies[i].speedX;
//        }
//    }
//}
//
//void diveAttack(float px)
//{
//    if ((glfwGetTime() - lastDiveTime) < diveIntervalVar)
//        return;
//    int start = (FORMATION_ROWS - 1) * FORMATION_COLS, end = start + FORMATION_COLS;
//    int cand[FORMATION_COLS], cnt = 0;
//    for (int i = start; i < end; i++)
//        if (enemies[i].active && !enemies[i].diving)
//            cand[cnt++] = i;
//    if (!cnt)
//        return;
//    int pick = cand[rand() % cnt];
//    float dx = px - enemies[pick].x, dy = STARTPLY - enemies[pick].y;
//    float len = sqrtf(dx * dx + dy * dy);
//    enemies[pick].speedX = DIVE_SPEED * dx / len;
//    enemies[pick].speedY = DIVE_SPEED * dy / len;
//    enemies[pick].diving = 1;
//    lastDiveTime = glfwGetTime();
//}
//
//void loadHighscores(const char* filename) {
//    FILE* file = fopen(filename, "r");
//    if (!file) return;
//    for (int i = 0; i < MAX_SCORES; i++)
//        fscanf(file, "%d", &highscores[i]);
//    fclose(file);
//}
//void saveHighscores(const char* filename) {
//    FILE* file = fopen(filename, "w");
//    if (!file) return;
//    for (int i = 0; i < MAX_SCORES; i++)
//        fprintf(file, "%d\n", highscores[i]);
//    fclose(file);
//}
//
//void addScore(int score) {
//    highscores[MAX_SCORES - 1] = score;
//    for (int i = MAX_SCORES - 1; i > 0; i--) {
//        if (highscores[i] > highscores[i - 1]) {
//            int tmp = highscores[i];
//            highscores[i] = highscores[i - 1];
//            highscores[i - 1] = tmp;
//        }
//        else break;
//    }
//}
//void checkDiveCollisions(float playerX)
//{
//    for (int i = 0; i < MAX_ENEMIES; i++)
//    {
//        if (enemies[i].active && enemies[i].diving)
//        {
//            float dx = enemies[i].x - playerX;
//            float dy = enemies[i].y - STARTPLY;
//            if ((fabsf(dx) <= PLAYER_COLLIDE_RX + ENEMY_SIZEX) && (fabsf(dy) <= PLAYER_COLLIDE_RY + ENEMY_SIZEY))
//            {
//                playerHits++;
//                playerIsHit = 1;
//                enemies[i].lives = 0;
//                enemies[i].active = 0;
//                kills++;
//                score += 10;
//                enemies[i].diving = 0;
//#if !PROFILING_MODE
//                if (playerHits >= PLAYER_HITS_TO_DIE) {
//                    addScore(score);
//                    saveHighscores("scores.txt");
//                    gameState = STATE_MENU;
//                    wave = 0;
//                    score = 0;
//                }
//#endif
//            }
//        }
//    }
//}
//
//void updatePlayerHits(float px)
//{
//    for (int i = 0; i < MAX_BULLETS; i++) {
//        if (!bullets[i].active || bullets[i].dir != -1) continue;
//        if ((fabs(bullets[i].x - px) <= PLAYER_COLLIDE_RX) &&
//            (fabs(bullets[i].y - STARTPLY) <= PLAYER_COLLIDE_RY)) {
//            playerHits++;
//            playerIsHit = 1;
//            bullets[i].active = 0;
//            bulletCount--;
//#if !PROFILING_MODE
//            if (playerHits >= PLAYER_HITS_TO_DIE)
//            {
//                addScore(score);
//                saveHighscores("scores.txt");
//                wave = 0;
//                score = 0;
//                gameState = STATE_MENU;
//            }
//#endif
//        }
//    }
//}
//
//void drawEnemiesInstanced(unsigned int texture, mat4 model, mat4 view, mat4 projection)
//{
//    int instanceCount = 0;
//
//    beginDoubleBufferUpdate(&enemyDoubleBuffer);
//    char* instanceData = (char*)enemyDoubleBuffer.mappedData;
//
//    for (int i = 0; i < MAX_ENEMIES; i++) {
//        if (!enemies[i].active) continue;
//        float* offset = (float*)(instanceData + instanceCount * 16);
//        int* isHit = (int*)(instanceData + instanceCount * 16 + 12);
//        offset[0] = enemies[i].x;
//        offset[1] = enemies[i].y;
//        offset[2] = 0.0f;
//        *isHit = enemies[i].hit;
//        instanceCount++;
//    }
//
//    endDoubleBufferUpdate(&enemyDoubleBuffer);
//
//    if (instanceCount == 0) return;
//
//    // Используем предыдущий буфер (который уже готов)
//    int renderBuffer = (enemyDoubleBuffer.currentBuffer + 1) % 2;
//    glBindBuffer(GL_ARRAY_BUFFER, enemyDoubleBuffer.buffers[renderBuffer]);
//
//    glUseProgram(enemyShader);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glUniform1i(glGetUniformLocation(enemyShader, "texture1"), 0);
//    glUniformMatrix4fv(glGetUniformLocation(enemyShader, "model"), 1, GL_FALSE, &model[0][0]);
//    glUniformMatrix4fv(glGetUniformLocation(enemyShader, "view"), 1, GL_FALSE, &view[0][0]);
//    glUniformMatrix4fv(glGetUniformLocation(enemyShader, "projection"), 1, GL_FALSE, &projection[0][0]);
//
//    glBindVertexArray(enemyVAO);
//    draw_call_count++;
//    glDrawArraysInstanced(GL_TRIANGLES, 0, enemymodel.numFaces, instanceCount);
//    glBindVertexArray(0);
//
//    for (int i = 0; i < MAX_ENEMIES; i++) {
//        enemies[i].hit = 0;
//    }
//}
//
//void drawPlayer(unsigned int texture, float x, mat4 model, mat4 view, mat4 projection)
//{
//    glUseProgram(playerShader);
//    glUniform3f(glGetUniformLocation(playerShader, "offset"), x, 0.0f, 0.0f);
//    glUniform1i(glGetUniformLocation(playerShader, "isHit"), playerIsHit);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glUniform1i(glGetUniformLocation(playerShader, "texture1"), 0);
//    glUniformMatrix4fv(glGetUniformLocation(playerShader, "model"), 1, GL_FALSE, &model[0][0]);
//    glUniformMatrix4fv(glGetUniformLocation(playerShader, "view"), 1, GL_FALSE, &view[0][0]);
//    glUniformMatrix4fv(glGetUniformLocation(playerShader, "projection"), 1, GL_FALSE, &projection[0][0]);
//    glBindVertexArray(playerVAO);
//    draw_call_count++;
//    glDrawArrays(GL_TRIANGLES, 0, playermodel.numFaces);
//    glBindVertexArray(0);
//}
//
//void processInput(GLFWwindow* w, float* x)
//{
//    if (glfwGetKey(w, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(w, 1);
//    if (glfwGetKey(w, GLFW_KEY_LEFT) == GLFW_PRESS && *x > -SCREEN_LIMIT_X && (glfwGetKey(w, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS))
//        *x -= 0.01f;
//    if (glfwGetKey(w, GLFW_KEY_RIGHT) == GLFW_PRESS && *x < SCREEN_LIMIT_X && (glfwGetKey(w, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS))
//        *x += 0.01f;
//    if (glfwGetKey(w, GLFW_KEY_LEFT) == GLFW_PRESS && *x > -SCREEN_LIMIT_X && (glfwGetKey(w, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)) {
//        *x -= 0.004f;
//    }
//    if (glfwGetKey(w, GLFW_KEY_RIGHT) == GLFW_PRESS && *x < SCREEN_LIMIT_X && (glfwGetKey(w, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)) {
//        *x += 0.004f;
//    }
//    if (glfwGetKey(w, GLFW_KEY_SPACE) == GLFW_PRESS)
//        shootBullet(*x);
//}
//
//unsigned int loadTexture(const char* path)
//{
//    unsigned int texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
//    if (!data)
//    {
//        printf("Failed to load texture: %s\n", stbi_failure_reason());
//        return 0;
//    }
//
//    GLenum internalFormat, dataFormat;
//    if (nrChannels == 1) {
//        internalFormat = dataFormat = GL_RED;
//    }
//    else if (nrChannels == 3) {
//        internalFormat = dataFormat = GL_RGB;
//    }
//    else if (nrChannels == 4) {
//        internalFormat = dataFormat = GL_RGBA;
//    }
//    else {
//        internalFormat = dataFormat = GL_RGBA;
//    }
//
//    glTexImage2D(GL_TEXTURE_2D, 0,
//        internalFormat,
//        width, height,
//        0,
//        dataFormat,
//        GL_UNSIGNED_BYTE,
//        data);
//    glGenerateMipmap(GL_TEXTURE_2D);
//
//    stbi_image_free(data);
//    return texture;
//}
//
//void loadObj(const char* path, Model* obmodel, float scale, float zoffset, float ydir, float yoffset, int change) {
//    FILE* file = fopen(path, "r");
//    if (!file) {
//        printf("Failed to open OBJ file: %s\n", path);
//        return;
//    }
//
//    unsigned int maxVertices = 100000, maxTexCoords = 100000, maxNormals = 100000, maxFaces = 100000;
//    obmodel->vertices = malloc(maxVertices * sizeof(vec3));
//    obmodel->texCoords = malloc(maxTexCoords * sizeof(vec2));
//    obmodel->normals = malloc(maxNormals * sizeof(vec3));
//    obmodel->faces = malloc(maxFaces * sizeof(Face));
//
//    int y = 1;
//    int z = 2;
//    if (change) {
//        z = 1;
//        y = 2;
//    }
//    char line[512];
//    int offset = 0;
//    while (fgets(line, sizeof(line), file)) {
//        char* ind = line;
//        if (strncmp(line, "v ", 2) == 0) {
//            sscanf(line, "v %f %f %f", &(obmodel->vertices[obmodel->numVertices])[0],
//                &(obmodel->vertices[obmodel->numVertices])[y],
//                &(obmodel->vertices[obmodel->numVertices])[z]);
//
//            obmodel->vertices[obmodel->numVertices][0] *= scale;
//            obmodel->vertices[obmodel->numVertices][z] *= scale;
//            obmodel->vertices[obmodel->numVertices][y] *= (scale * ydir);
//            obmodel->vertices[obmodel->numVertices][1] += zoffset;
//            obmodel->vertices[obmodel->numVertices][1] += yoffset;
//
//            obmodel->numVertices++;
//        }
//        else if (strncmp(line, "vt ", 3) == 0) {
//            sscanf(line, "vt %f %f", &obmodel->texCoords[obmodel->numTexCoords][0],
//                &obmodel->texCoords[obmodel->numTexCoords][1]);
//            obmodel->numTexCoords++;
//        }
//        else if (strncmp(line, "vn ", 3) == 0) {
//            sscanf(line, "vn %f %f %f", &obmodel->normals[obmodel->numNormals][0],
//                &obmodel->normals[obmodel->numNormals][1],
//                &obmodel->normals[obmodel->numNormals][2]);
//            obmodel->numNormals++;
//        }
//        else if (strncmp(line, "f ", 2) == 0) {
//            unsigned int v[3], vt[3], vn[3];
//            int result = sscanf(ind, "f %u/%u/%u %u/%u/%u %u/%u/%u%n",
//                &v[0], &vt[0], &vn[0],
//                &v[1], &vt[1], &vn[1],
//                &v[2], &vt[2], &vn[2], &offset);
//            ind += offset;
//            offset = 0;
//            for (int i = 0; i < 3; i++) {
//                obmodel->faces[obmodel->numFaces].vertexIndex = v[i] - 1;
//                obmodel->faces[obmodel->numFaces].uvIndex = vt[i] - 1;
//                obmodel->faces[obmodel->numFaces].normalIndex = vn[i] - 1;
//                obmodel->numFaces++;
//            }
//            while (sscanf(ind, "%u/%u/%u%n", &v[1], &vt[1], &vn[1], &offset) == 3) {
//                obmodel->faces[obmodel->numFaces].vertexIndex = v[0] - 1;
//                obmodel->faces[obmodel->numFaces].uvIndex = vt[0] - 1;
//                obmodel->faces[obmodel->numFaces].normalIndex = vn[0] - 1;
//                obmodel->numFaces++;
//                obmodel->faces[obmodel->numFaces].vertexIndex = v[2] - 1;
//                obmodel->faces[obmodel->numFaces].uvIndex = vt[2] - 1;
//                obmodel->faces[obmodel->numFaces].normalIndex = vn[2] - 1;
//                obmodel->numFaces++;
//                obmodel->faces[obmodel->numFaces].vertexIndex = v[1] - 1;
//                obmodel->faces[obmodel->numFaces].uvIndex = vt[1] - 1;
//                obmodel->faces[obmodel->numFaces].normalIndex = vn[1] - 1;
//                obmodel->numFaces++;
//                v[2] = v[1];
//                vt[2] = vt[1];
//                vn[2] = vn[1];
//                ind += offset;
//                offset = 0;
//            }
//        }
//    }
//
//    fclose(file);
//}
//
//void freeModel(Model* obmodel) {
//    free(obmodel->vertices);
//    free(obmodel->texCoords);
//    free(obmodel->normals);
//    free(obmodel->faces);
//
//    obmodel->numVertices = 0;
//    obmodel->numTexCoords = 0;
//    obmodel->numNormals = 0;
//    obmodel->numFaces = 0;
//}
//
//void compileTextShader() {
//    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vs, 1, &textVertexSrc, NULL);
//    glCompileShader(vs);
//
//    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fs, 1, &textFragmentSrc, NULL);
//    glCompileShader(fs);
//
//    textShader = glCreateProgram();
//    glAttachShader(textShader, vs);
//    glAttachShader(textShader, fs);
//    glLinkProgram(textShader);
//
//    glDeleteShader(vs);
//    glDeleteShader(fs);
//}
//
//void setupText() {
//    glGenVertexArrays(1, &VAO_text);
//    glGenBuffers(1, &VBO_text);
//    glBindVertexArray(VAO_text);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO_text);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
//    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    fontTexture = loadTexture("res/font.png");
//}
//
//void renderText(const char* text, float x, float y, float scale) {
//    glUseProgram(textShader);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, fontTexture);
//    glUniform1i(glGetUniformLocation(textShader, "font"), 0);
//    glBindVertexArray(VAO_text);
//
//    float xpos = x;
//    for (const char* p = text; *p; p++) {
//        int c = (unsigned char)(*p);
//        float tx = (c % 16) / 16.0f;
//        float ty = (c / 16) / 16.0f;
//        float tw = 1.0f / 16.0f;
//        float th = 1.0f / 16.0f;
//        float w = scale * tw;
//        float h = scale * th;
//        float vertices[6][4] = {
//            { xpos,     y + h, tx,        ty },
//            { xpos,     y,     tx,        ty + th },
//            { xpos + w, y,     tx + tw,   ty + th },
//
//            { xpos,     y + h, tx,        ty },
//            { xpos + w, y,     tx + tw,   ty + th },
//            { xpos + w, y + h, tx + tw,   ty }
//        };
//        glBindBuffer(GL_ARRAY_BUFFER, VBO_text);
//        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
//        draw_call_count++;
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        xpos += w;
//    }
//    glBindVertexArray(0);
//}
//void renderControls(GLFWwindow* window) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    renderText("Controls:", -0.5f, 0.5f, 1.2f);
//    renderText("</> - move", -0.5f, 0.3f, 1.1f);
//    renderText("Shift - focus", -0.5f, 0.1f, 1.1f);
//    renderText("Spacebar - shoot", -0.5f, -0.1f, 1.1f);
//    renderText("Esc - close game", -0.5f, -0.3f, 1.1f);
//    renderText("X - back to menu", -0.5f, -0.5f, 1.1f);
//    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
//        gameState = STATE_MENU;
//    }
//}
//void renderMenu(GLFWwindow* window) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glUseProgram(menuShader);
//
//    renderText("PLAY", -0.15f, -0.025f, 1.2f);
//    renderText("CONTROLS", -0.3f, -0.175f, 1.2f);
//    renderText("HIGHSCORES", -0.37f, -0.325f, 1.2f);
//
//    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
//        gameState = STATE_PLAYING;
//    }
//    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
//        addScore(score);
//        saveHighscores("scores.txt");
//        gameState = STATE_MENU;
//        score = 0;
//    }
//
//    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
//        double mx, my;
//        int w, h;
//        glfwGetCursorPos(window, &mx, &my);
//        glfwGetWindowSize(window, &w, &h);
//        float ndc_x = mx / w * 2 - 1;
//        float ndc_y = (h - my) / h * 2 - 1;
//
//        if (ndc_x >= -0.4f && ndc_x <= 0.4f) {
//            if (ndc_y >= 0.0f && ndc_y <= 0.1f)
//                gameState = STATE_PLAYING;
//            else if (ndc_y >= -0.15f && ndc_y <= -0.05f)
//                gameState = STATE_CONTROLS;
//            else if (ndc_y >= -0.3f && ndc_y <= -0.2f)
//                gameState = STATE_HIGHSCORES;
//        }
//    }
//}
//void renderHighscores(GLFWwindow* window) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    renderText("High Scores:", -0.5f, 0.5f, 1.0f);
//    char buffer[64];
//    for (int i = 0; i < MAX_SCORES; i++) {
//        snprintf(buffer, sizeof(buffer), "%d. %d", i + 1, highscores[i]);
//        renderText(buffer, -0.4f, 0.35f - i * 0.08f, 0.8f);
//    }
//
//    renderText("X - back to menu", -0.4f, -0.5f, 0.7f);
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
//        glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
//        gameState = STATE_MENU;
//    }
//}
//
//void renderGame(unsigned int primprog, unsigned int texture, unsigned int VAO_bg) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glUseProgram(primprog);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glBindVertexArray(VAO_bg);
//    draw_call_count++;
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//}
//
//int main()
//{
//    gameState = STATE_MENU;
//    loadHighscores("scores.txt");
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
//    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
//    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "Galaxian3D", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSwapInterval(1);
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//        return -1;
//    glViewport(0, 0, mode->width, mode->height);
//
//    mat4 model, view, projection;
//    glm_mat4_identity(model);
//    glm_perspective(glm_rad(45.0f), (float)(mode->width) / (float)(mode->height), 0.1f, 100.0f, projection);
//
//    vec3 eye = { 0.0f, -2.0f, 1.0f };
//    vec3 center = { 0.0f, 0.0f, 0.0f };
//    vec3 up = { 0.0f, 1.0f, 1.0f };
//    glm_lookat(eye, center, up, view);
//
//    // === Фоновый шейдер ===
//    unsigned int pvs = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(pvs, 1, &primvetexshader, NULL);
//    glCompileShader(pvs);
//    checkShaderCompileErrors(pvs);
//    unsigned int pfs = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(pfs, 1, &primefragmentshader, NULL);
//    glCompileShader(pfs);
//    checkShaderCompileErrors(pfs);
//    unsigned int primprog = glCreateProgram();
//    glAttachShader(primprog, pvs);
//    glAttachShader(primprog, pfs);
//    glLinkProgram(primprog);
//    glDeleteShader(pvs);
//    glDeleteShader(pfs);
//
//    // === Фон ===
//    float backgroundVertices[] = {
//        1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
//        1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
//        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
//        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f
//    };
//    unsigned int indices[] = { 0, 1, 3, 1, 2, 3 };
//    unsigned int texture = loadTexture("res/back.png");
//    unsigned int VBO_bg, VAO_bg, EBO;
//    glGenVertexArrays(1, &VAO_bg);
//    glGenBuffers(1, &VBO_bg);
//    glGenBuffers(1, &EBO);
//    glBindVertexArray(VAO_bg);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO_bg);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(backgroundVertices), backgroundVertices, GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    // === Пули ===
//    float vb[] = {
//        -0.005f, -0.07f, 0, 1.0f, 0.65f, 0.0f,
//         0.005f, -0.07f, 0, 1.0f, 0.65f, 0.0f,
//         0.005f, -0.03f, 0, 1.0f, 0.65f, 0.0f,
//        -0.005f, -0.07f, 0, 1.0f, 0.65f, 0.0f,
//         0.005f, -0.03f, 0, 1.0f, 0.65f, 0.0f,
//        -0.005f, -0.03f, 0, 1.0f, 0.65f, 0.0f
//    };
//
//    glGenVertexArrays(1, &VAO_b);
//    glGenBuffers(1, &VBO_b);
//    glBindVertexArray(VAO_b);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO_b);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vb), vb, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//    // Инициализация double buffering для пуль
//    initDoubleBuffer(&bulletDoubleBuffer, MAX_BULLETS * 3 * sizeof(float));
//    glBindBuffer(GL_ARRAY_BUFFER, bulletDoubleBuffer.buffers[0]);
//    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(2);
//    glVertexAttribDivisor(2, 1);
//
//    glBindVertexArray(0);
//
//    // === Шейдер пуль ===
//    unsigned int bulletVS = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(bulletVS, 1, &instancedBulletVertexShader, NULL);
//    glCompileShader(bulletVS);
//    checkShaderCompileErrors(bulletVS);
//    unsigned int bulletFS = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(bulletFS, 1, &bulletFragmentShader, NULL);
//    glCompileShader(bulletFS);
//    checkShaderCompileErrors(bulletFS);
//    bulletShader = glCreateProgram();
//    glAttachShader(bulletShader, bulletVS);
//    glAttachShader(bulletShader, bulletFS);
//    glLinkProgram(bulletShader);
//    glDeleteShader(bulletVS);
//    glDeleteShader(bulletFS);
//
//    // === Шейдер врагов ===
//    unsigned int enemyVS = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(enemyVS, 1, &instancedEnemyVertexShader, NULL);
//    glCompileShader(enemyVS);
//    checkShaderCompileErrors(enemyVS);
//    unsigned int enemyFS = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(enemyFS, 1, &instancedEnemyFragmentShader, NULL);
//    glCompileShader(enemyFS);
//    checkShaderCompileErrors(enemyFS);
//    enemyShader = glCreateProgram();
//    glAttachShader(enemyShader, enemyVS);
//    glAttachShader(enemyShader, enemyFS);
//    glLinkProgram(enemyShader);
//    glDeleteShader(enemyVS);
//    glDeleteShader(enemyFS);
//
//    // === Враги ===
//    memset(&enemymodel, 0, sizeof(Model));
//    loadObj("res/fighter.obj", &enemymodel, .05f, 0.2f, 1.0f, -0.3f, 0);
//
//    glGenVertexArrays(1, &enemyVAO);
//    glGenBuffers(1, &enemyVBO);
//    glBindVertexArray(enemyVAO);
//
//    float* vertexData = malloc(enemymodel.numFaces * 3 * 8 * sizeof(float));
//    unsigned int idx = 0;
//    for (unsigned int i = 0; i < enemymodel.numFaces; i++) {
//        Face face = enemymodel.faces[i];
//        vertexData[idx++] = enemymodel.vertices[face.vertexIndex][0];
//        vertexData[idx++] = enemymodel.vertices[face.vertexIndex][1];
//        vertexData[idx++] = enemymodel.vertices[face.vertexIndex][2];
//        vertexData[idx++] = enemymodel.texCoords[face.uvIndex][0];
//        vertexData[idx++] = enemymodel.texCoords[face.uvIndex][1];
//        vertexData[idx++] = enemymodel.normals[face.normalIndex][0];
//        vertexData[idx++] = enemymodel.normals[face.normalIndex][1];
//        vertexData[idx++] = enemymodel.normals[face.normalIndex][2];
//    }
//
//    glBindBuffer(GL_ARRAY_BUFFER, enemyVBO);
//    glBufferData(GL_ARRAY_BUFFER, enemymodel.numFaces * 3 * 8 * sizeof(float), vertexData, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//    // Инициализация double buffering для врагов
//    initDoubleBuffer(&enemyDoubleBuffer, MAX_ENEMIES * 16);
//    glBindBuffer(GL_ARRAY_BUFFER, enemyDoubleBuffer.buffers[0]);
//
//    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 16, (void*)0);
//    glEnableVertexAttribArray(3);
//    glVertexAttribDivisor(3, 1);
//
//    glVertexAttribIPointer(4, 1, GL_INT, 16, (void*)(12));
//    glEnableVertexAttribArray(4);
//    glVertexAttribDivisor(4, 1);
//
//    free(vertexData);
//    glBindVertexArray(0);
//
//    unsigned int enemytexture = loadTexture("res/fighter_texture.jpg");
//
//    // === Игрок ===
//    memset(&playermodel, 0, sizeof(Model));
//    loadObj("res/SpaseShip.obj", &playermodel, .05f, -0.2f, 1.0f, -0.3f, 1);
//
//    glGenVertexArrays(1, &playerVAO);
//    glGenBuffers(1, &playerVBO);
//    glBindVertexArray(playerVAO);
//
//    float* playerVertexData = malloc(playermodel.numFaces * 3 * 8 * sizeof(float));
//    idx = 0;
//    for (unsigned int i = 0; i < playermodel.numFaces; i++) {
//        Face face = playermodel.faces[i];
//        playerVertexData[idx++] = playermodel.vertices[face.vertexIndex][0];
//        playerVertexData[idx++] = playermodel.vertices[face.vertexIndex][1];
//        playerVertexData[idx++] = playermodel.vertices[face.vertexIndex][2];
//        playerVertexData[idx++] = playermodel.texCoords[face.uvIndex][0];
//        playerVertexData[idx++] = playermodel.texCoords[face.uvIndex][1];
//        playerVertexData[idx++] = playermodel.normals[face.normalIndex][0];
//        playerVertexData[idx++] = playermodel.normals[face.normalIndex][1];
//        playerVertexData[idx++] = playermodel.normals[face.normalIndex][2];
//    }
//    glBindBuffer(GL_ARRAY_BUFFER, playerVBO);
//    glBufferData(GL_ARRAY_BUFFER, playermodel.numFaces * 3 * 8 * sizeof(float), playerVertexData, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//    free(playerVertexData);
//    glBindVertexArray(0);
//    unsigned int shiptexture = loadTexture("res/Ship_texture.png");
//
//    // === Шейдер игрока ===
//    unsigned int mvs = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(mvs, 1, &modelvertexShaderSource, NULL);
//    glCompileShader(mvs);
//    checkShaderCompileErrors(mvs);
//    unsigned int mfs = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(mfs, 1, &modelfragmentShaderSource, NULL);
//    glCompileShader(mfs);
//    checkShaderCompileErrors(mfs);
//    playerShader = glCreateProgram();
//    glAttachShader(playerShader, mvs);
//    glAttachShader(playerShader, mfs);
//    glLinkProgram(playerShader);
//    glDeleteShader(mvs);
//    glDeleteShader(mfs);
//
//    srand((unsigned)time(NULL));
//    spawnFormation();
//    lastDiveTime = glfwGetTime();
//
//#if PROFILING_MODE
//    for (int i = 0; i < MAX_ENEMIES; i++) {
//        enemies[i].active = 1;
//        enemies[i].lives = 100;
//        enemies[i].diving = 1;
//        enemies[i].hit = 0;
//        enemies[i].x = ((rand() % 200) / 100.0f) - 1.0f;
//        enemies[i].y = ((rand() % 200) / 100.0f) - 0.5f;
//    }
//    bulletCount = MAX_BULLETS;
//    for (int i = 0; i < MAX_BULLETS; i++) {
//        bullets[i].x = ((rand() % 200) / 100.0f) - 1.0f;
//        bullets[i].y = ((rand() % 200) / 100.0f) - 1.0f;
//        bullets[i].dir = (rand() % 2) ? 1 : -1;
//        bullets[i].active = 1;
//    }
//    score = 999999;
//    wave = 99;
//#endif
//
//    compileTextShader();
//    setupText();
//    const float PLAYER_X = 0.0f;
//    float x = PLAYER_X;
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glEnable(GL_DEPTH_TEST);
//
//    FILE* profileLog = NULL;
//#if PROFILING_MODE
//    profileLog = fopen("profile_fully_instanced.txt", "w");
//    if (profileLog) {
//        fprintf(profileLog, "Time_sec\tFPS\tFrameTime_ms\tActiveEnemies\tActiveBullets\tDrawCalls\n");
//        fflush(profileLog);
//    }
//#endif
//
//    double lastFrameTime = glfwGetTime();
//    double lastReportTime = lastFrameTime;
//
//    while (!glfwWindowShouldClose(window))
//    {
//        double currentTime = glfwGetTime();
//        double deltaTime = currentTime - lastFrameTime;
//        lastFrameTime = currentTime;
//
//#if !PROFILING_MODE
//        if (gameState == STATE_PLAYING) {
//            processInput(window, &x);
//        }
//#endif
//
//        switch (gameState) {
//        case STATE_MENU:
//            renderMenu(window);
//            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//                glfwSetWindowShouldClose(window, 1);
//            break;
//        case STATE_PLAYING:
//            draw_call_count = 0;
//#if !PROFILING_MODE
//            updateEnemy();
//            updateBullets();
//            for (int j = 0; j < MAX_ENEMIES; j++)
//                if (enemies[j].active && rand() % 500 == 0)
//                    shootEnemyBullet(enemies[j].x, enemies[j].y, enemyShotInterval);
//            updateEnemyMovement(x);
//            diveAttack(x);
//            for (int i = 0; i < MAX_ENEMIES; i++)
//                if (enemies[i].active && enemies[i].diving)
//                    shootEnemyBullet(enemies[i].x, enemies[i].y, (enemyShotInterval / 2));
//            checkDiveCollisions(x);
//            updatePlayerHits(x);
//            {
//                int alive = 0;
//                for (int i = 0; i < MAX_ENEMIES; i++)
//                    if (enemies[i].active) alive++;
//                if (alive == 0) {
//                    score += baseWaveScore + wave * 100;
//                    wave++;
//                    enemyShotInterval *= 0.9f;
//                    diveIntervalVar *= 0.9f;
//                    spawnFormation();
//                }
//            }
//#endif
//
//            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//            renderGame(primprog, texture, VAO_bg);
//            drawBullets(model, view, projection);
//            drawEnemiesInstanced(enemytexture, model, view, projection);
//            drawPlayer(shiptexture, x, model, view, projection);
//            playerIsHit = 0;
//
//            char scoreText[64];
//            sprintf(scoreText, "Score: %d", score);
//            GLint prevDepthFunc;
//            glGetIntegerv(GL_DEPTH_FUNC, &prevDepthFunc);
//            glDepthFunc(GL_ALWAYS);
//            renderText(scoreText, -0.95f, 0.9f, 1.0f);
//            glDepthFunc(prevDepthFunc);
//            break;
//        case STATE_CONTROLS:
//            renderControls(window);
//            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//                glfwSetWindowShouldClose(window, 1);
//            break;
//        case STATE_HIGHSCORES:
//            renderHighscores(window);
//            if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//                glfwSetWindowShouldClose(window, 1);
//            break;
//        }
//
//#if PROFILING_MODE
//        if (profileLog && (currentTime - lastReportTime >= 1.0)) {
//            double fps = 1.0 / deltaTime;
//            double frameTimeMs = deltaTime * 1000.0;
//            int activeEnemies = 0;
//            for (int i = 0; i < MAX_ENEMIES; i++) if (enemies[i].active) activeEnemies++;
//            int activeBullets = bulletCount;
//
//            fprintf(profileLog, "%.3f\t%.2f\t%.3f\t%d\t%d\t%lld\n",
//                currentTime,
//                fps,
//                frameTimeMs,
//                activeEnemies,
//                activeBullets,
//                draw_call_count);
//            fflush(profileLog);
//            lastReportTime = currentTime;
//        }
//#endif
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//#if PROFILING_MODE
//    if (profileLog) fclose(profileLog);
//#endif
//
//    // === Очистка ===
//    cleanupDoubleBuffer(&bulletDoubleBuffer);
//    cleanupDoubleBuffer(&enemyDoubleBuffer);
//    glDeleteVertexArrays(1, &playerVAO);
//    glDeleteBuffers(1, &playerVBO);
//    glDeleteProgram(playerShader);
//    glDeleteVertexArrays(1, &VAO_b);
//    glDeleteBuffers(1, &VBO_b);
//    glDeleteProgram(bulletShader);
//    glDeleteVertexArrays(1, &enemyVAO);
//    glDeleteBuffers(1, &enemyVBO);
//    glDeleteProgram(enemyShader);
//    glDeleteVertexArrays(1, &VAO_bg);
//    glDeleteBuffers(1, &VBO_bg);
//    glDeleteProgram(primprog);
//    glDeleteVertexArrays(1, &VAO_text);
//    glDeleteBuffers(1, &VBO_text);
//    freeModel(&playermodel);
//    freeModel(&enemymodel);
//    glfwTerminate();
//    return 0;
//}