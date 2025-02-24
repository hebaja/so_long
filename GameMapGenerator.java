import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class GameMapGenerator {
    public static void main(String[] args) {
        int width = 25;
        int height = 31;
        char[][] gameMap = new char[height][width];
        Random rand = new Random();

        // Fill the map with empty spaces ('0')
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                gameMap[y][x] = '0';
            }
        }

        // Add walls around the border
        for (int x = 0; x < width; x++) {
            gameMap[0][x] = '1';  // Top border
            gameMap[height - 1][x] = '1';  // Bottom border
        }
        for (int y = 0; y < height; y++) {
            gameMap[y][0] = '1';  // Left border
            gameMap[y][width - 1] = '1';  // Right border
        }

        // Generate random walls inside the map (~5% of the map)
        int numWalls = (int) (width * height * 0.15);
        for (int i = 0; i < numWalls; i++) {
            int x, y;
            do {
                x = rand.nextInt(width - 2) + 1;
                y = rand.nextInt(height - 2) + 1;
            } while (gameMap[y][x] != '0');  // Ensure it's placed in an empty space
            gameMap[y][x] = '1';
        }

        // Place collectibles (~7% of the map)
        int numCollectibles = (int) (width * height * 0.06);
        for (int i = 0; i < numCollectibles; i++) {
            int x, y;
            do {
                x = rand.nextInt(width - 2) + 1;
                y = rand.nextInt(height - 2) + 1;
            } while (gameMap[y][x] != '0');
            gameMap[y][x] = 'C';
        }

        // Place exit ('E')
        int exitX, exitY;
        do {
            exitX = rand.nextInt(width - 2) + 1;
            exitY = rand.nextInt(height - 2) + 1;
        } while (gameMap[exitY][exitX] != '0');
        gameMap[exitY][exitX] = 'E';

        // Place player ('P')
        int playerX, playerY;
        do {
            playerX = rand.nextInt(width - 2) + 1;
            playerY = rand.nextInt(height - 2) + 1;
        } while (gameMap[playerY][playerX] != '0');
        gameMap[playerY][playerX] = 'P';

        // Save the map to a file
        try (FileWriter writer = new FileWriter("game_map.txt")) {
            for (char[] row : gameMap) {
                writer.write(row);
                writer.write("\n");
            }
            System.out.println("Game map saved as game_map.txt");
        } catch (IOException e) {
            System.err.println("Error saving the map: " + e.getMessage());
        }
    }
}
