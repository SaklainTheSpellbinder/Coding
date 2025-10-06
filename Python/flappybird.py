import pygame
import sys
import random

# ----------------- Game Functions -----------------

def draw_floor():
    """Draws and animates the moving floor as two rectangles."""
    pygame.draw.rect(screen, FLOOR_BROWN, (floor_x_pos, 650, 432, 118))
    pygame.draw.rect(screen, FLOOR_BROWN, (floor_x_pos + 432, 650, 432, 118))

def create_pipe():
    """Creates a new pipe pair (two rectangles) with a random height."""
    random_pipe_pos = random.choice(pipe_height)
    # The pipe width is set to 70
    bottom_pipe = pygame.Rect(500, random_pipe_pos, 70, 400)
    top_pipe = pygame.Rect(500, random_pipe_pos - 200 - 400, 70, 400) # 200px gap
    return bottom_pipe, top_pipe

def move_pipes(pipes):
    """Moves a list of pipe rectangles to the left."""
    for pipe in pipes:
        pipe.centerx -= 4
    # Filter out pipes that have moved off-screen
    visible_pipes = [pipe for pipe in pipes if pipe.right > -50]
    return visible_pipes

def draw_pipes(pipes):
    """Draws all pipe rectangles in the list."""
    for pipe in pipes:
        pygame.draw.rect(screen, PIPE_GREEN, pipe)

def check_collision(pipes):
    """Checks for collisions between the bird and pipes, floor, or ceiling."""
    # Collision with pipes
    for pipe in pipes:
        if bird_rect.colliderect(pipe):
            if sound_enabled: hit_sound.play()
            return False

    # Collision with floor or ceiling
    if bird_rect.top <= -50 or bird_rect.bottom >= 650:
        if sound_enabled: hit_sound.play()
        return False

    return True

def score_display(game_state):
    """Displays the current score and high score as text."""
    if game_state == 'main_game':
        score_surface = game_font.render(str(int(score)), True, WHITE)
        score_rect = score_surface.get_rect(center=(216, 100))
        screen.blit(score_surface, score_rect)
    elif game_state == 'game_over':
        # Current score
        score_surface = game_font.render(f'Score: {int(score)}', True, WHITE)
        score_rect = score_surface.get_rect(center=(216, 100))
        screen.blit(score_surface, score_rect)

        # High score
        high_score_surface = game_font.render(f'High score: {int(high_score)}', True, WHITE)
        high_score_rect = high_score_surface.get_rect(center=(216, 620))
        screen.blit(high_score_surface, high_score_rect)
        
        # Restart message
        restart_surface = game_font.render('Press Space to Play', True, WHITE)
        restart_rect = restart_surface.get_rect(center=(216, screen_height / 2))
        screen.blit(restart_surface, restart_rect)


def update_high_score(current_score, high):
    """Updates the high score if the current score is greater."""
    if current_score > high:
        high = current_score
    return high

# ----------------- Game Setup -----------------

pygame.init()
screen_width = 432
screen_height = 768
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption('Flappy Bird Clone')
clock = pygame.time.Clock()

# Use a default font since we don't need external files
game_font = pygame.font.SysFont('Arial', 40, bold=True)

# Define Colors
SKY_BLUE = (113, 197, 207)
BIRD_YELLOW = (255, 235, 59)
PIPE_GREEN = (41, 155, 59)
FLOOR_BROWN = (223, 205, 144)
WHITE = (255, 255, 255)


# ----------------- Game Variables -----------------

# Game state
game_active = False
score = 0
high_score = 0
pipe_score_check = True

# Physics
gravity = 0.20
bird_movement = 0
floor_x_pos = 0

# Bird rectangle
bird_rect = pygame.Rect(100, screen_height / 2, 40, 30)

# Pipes
pipe_list = []
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE, 1200) # Spawn a new pipe every 1.2 seconds
pipe_height = [300, 400, 500]

# Load Sounds (optional)
sound_enabled = False

# ----------------- Main Game Loop -----------------

while True:
    # Event Handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                if game_active:
                    # Make the bird jump
                    bird_movement = 0
                    bird_movement -= 7
                    if sound_enabled: flap_sound.play()
                else:
                    # Reset game
                    game_active = True
                    pipe_list.clear()
                    bird_rect.center = (100, screen_height / 2)
                    bird_movement = 0
                    score = 0
                    pipe_score_check = True

        if event.type == SPAWNPIPE and game_active:
            pipe_list.extend(create_pipe())

    # --- Drawing ---
    screen.fill(SKY_BLUE)

    if game_active:
        # --- Game Logic ---
        # Bird Movement
        bird_movement += gravity
        bird_rect.centery += bird_movement
        pygame.draw.ellipse(screen, BIRD_YELLOW, bird_rect) # Draw bird as an ellipse/oval

        # Collision Check
        game_active = check_collision(pipe_list)

        # Pipe Movement & Drawing
        pipe_list = move_pipes(pipe_list)
        draw_pipes(pipe_list)

        # Score Logic
        if pipe_list:
            pipe_center_x = pipe_list[0].centerx
            if 100 - 4 < pipe_center_x < 100 + 4 and pipe_score_check:
                score += 1
                if sound_enabled: score_sound.play()
                pipe_score_check = False
            if pipe_center_x < 90:
                pipe_score_check = True

        score_display('main_game')

    else: # Game Over Screen
        high_score = update_high_score(score, high_score)
        score_display('game_over')

    # Floor Movement
    floor_x_pos -= 1
    draw_floor()
    if floor_x_pos <= -432:
        floor_x_pos = 0

    # Update the display
    pygame.display.update()
    clock.tick(120) # Set frame rate to 120 FPS