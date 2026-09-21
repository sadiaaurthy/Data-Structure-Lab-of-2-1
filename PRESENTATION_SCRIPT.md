# FableOps: Synchronized Survival — Final Project Presentation Script

- **Course:** CSE 4402: Visual Programming Lab
- **Institution:** Islamic University of Technology (IUT)
- **Speaker:** Sadia Afrin Aurthy (Solo voiceover on behalf of the team)
- **Team Members:**
  - Fabian Mahdi (230041152)
  - Arefin Mahim (230041136)
  - Sadia Afrin Aurthy (230041114)
- **Format:** Screen recording of live gameplay in **Debug Mode** (No slides / PPT)
- **Key Shortcut:** `K` (Debug skip to bypass puzzle stages/objectives quickly for demo purposes)
- **Target Duration:** 5 to 7 minutes (Strict limit: 10 minutes)
- **GitHub Repository:** https://github.com/sadiaaurthy/NOX-SYNC

---

## 1. Introduction & Game Premise (0:00 – 0:45)

### Screen Action
> Show the game launching from VS Code or terminal into the JavaFX launcher menu. Keep the game window on screen.

### Spoken Script
> "Assalamu Alaikum and hello sir. I am Sadia Afrin Aurthy, presenting our final project for CSE 4402: Visual Programming Lab on behalf of our team: Fabian Mahdi, Arefin Mahim, and myself.
>
> Our project is **FableOps: Synchronized Survival**, a 2-player cooperative top-down survival game built in Java.
>
> The game is set inside Meridian Deep-Core Station, an underground facility where a prototype clean-energy reactor became unstable. The station's defense AI, the Warden, locked down the facility after safety overrides were rushed. Two specialists—the Breaker and the Listener—are sent in to restore containment through synchronized teamwork."

---

## 2. Proposal vs. Delivery: What We Built, Changed, and Dropped (0:45 – 2:00)

### Screen Action
> Show the launcher on screen, or switch briefly to VS Code showing the project structure (`launcher`, `core`, `lwjgl3`).

### Spoken Script
> "Before running through the gameplay, here is a quick review of how our final build compares to our project proposal:
>
> **What We Promised and Delivered:**
> * We proposed a 2-player cooperative game with asymmetric roles and strict co-op locks where neither player can progress alone.
> * We promised custom TCP networking built from scratch using pure Java sockets without external networking frameworks. We implemented a dual-socket system on ports 9090 and 9091.
> * We delivered all three planned levels: Level 1 for terminal puzzles and door security, Level 2 for maze loot and reactor core escort, and Level 3 for the boss encounter against the Warden.
> * We delivered a built-in single-PC **Debug Mode**, which we will use today to demonstrate both characters smoothly on a single screen.
>
> **What Changed from the Proposal:**
> * In our proposal, we planned to generate visuals procedurally using libGDX `ShapeRenderer`. During development, we decided that looked too basic, so we replaced it with hand-crafted pixel art maps, animated character sprite sheets, and bitmap collision masks.
> * We originally proposed a simpler Pokémon-style combat system for Level 3. We evolved this into a synchronized turn-based battle where players choose actions from a menu, coordinate attacks, and react to enemy turrets and drones.
>
> **What We Scoped Out:**
> * Our proposal mentioned a Spring Boot backend for online leaderboards and analytics. We dropped Spring Boot to keep the project focused entirely on direct, low-latency socket gameplay.
>
> **What We Added Extra:**
> * We built a full JavaFX desktop launcher with a pre-warmed OpenGL window so the game starts without loading pauses.
> * We added a 5x5 inventory with a real-time synchronized Shared Slot for trading items mid-combat.
> * We added Radmin VPN support so two players can connect across different Wi-Fi networks."

---

## 3. Live Demonstration in Debug Mode (2:00 – 5:15)

### Step A: Launcher & Entering Debug Mode (2:00 – 2:30)

#### Screen Action
> On the JavaFX launcher screen, press `D` to launch directly into Debug Mode. Show the split-screen game window open immediately.

#### Spoken Script
> "Now let us jump into the game.
>
> Although our engine supports full multiplayer over LAN and Radmin VPN, for this video demonstration I am using our built-in **Debug Mode** by pressing `D` on the launcher.
>
> Debug Mode runs both operatives on a single screen with split keyboard controls: Player 1, **The Breaker**, is controlled using WASD, while Player 2, **The Listener**, is controlled using the Arrow Keys. Since this is an evaluation demo and not a full playthrough, we also mapped a debug key—`K`—to skip stages so we can showcase all mechanics quickly without getting stuck on puzzle times."

---

### Step B: Level 1 — Access Ring: Terminals, Swarms & Plates (2:30 – 3:30)

#### Screen Action
> Move Listener to a terminal using Arrow Keys, press 'E', and show the puzzle popup. Intentionally enter an incorrect digit to show the Alert Meter rise and drones spawn. Move Breaker using WASD and attack drones with left-click melee swings.
> **Then press `K` once or twice to skip the remaining puzzle stages.**
> Move both characters onto the two pressure plates at the same time to open the exit door. Walk through to Level 2.

#### Spoken Script
> "Level 1 uses a split-screen view where each camera tracks its respective player inside the map borders.
>
> The Listener interacts with terminals using `E`. There are three puzzle stages: binary decoding, symbol ciphers, and a shared formula.
>
> If an incorrect code is entered, the station's Alert Meter increases and sends out a wave of security drones. The Breaker clears these threats using melee attacks.
>
> For this demo, I will press `K` to skip through the remaining stages. To unlock the exit gate, both players must step onto the two pressure plates simultaneously. Progression strictly requires both operatives working together."

---

### Step C: Level 2 — Reactor Maze, Loot & Core Meltdown (3:30 – 4:25)

#### Screen Action
> Move through Level 2. Press '1' for Breaker and '2' for Listener to show their 5x5 inventories. Pick up an item, place it into the Shared Slot, and show the other player taking it.
> **Press `K` to trigger the Core pickup state immediately (or walk to it).**
> Show the emergency countdown timer start on the HUD and drones spawning faster. Walk both players to the socket and insert the core to enter Level 3.

#### Spoken Script
> "In Level 2, players navigate a maze to locate the reactor core while scavenging supplies like ammo, shields, and medkits.
>
> Pressing the inventory keys opens each player's 5x5 grid. We built a **Shared Transfer Slot** so players can pass supplies to each other in real time during combat.
>
> To show the main objective quickly, I will press `K` to trigger the core pickup. Containment drops, the emergency countdown timer starts on the HUD, and enemy drones spawn twice as fast. Both players must escort the core and insert it into the socket before time runs out."

---

### Step D: Level 3 — The Warden Boss Fight (4:25 – 5:15)

#### Screen Action
> Show Level 3 boss arena with the Spider Warden, defense drones, and turrets. Show the turn panel menu. Select actions for both characters (Attack / Shoot / TNT / Defend), submit choices, and show the enemy response phase.

#### Spoken Script
> "Level 3 is the final encounter against the Warden AI and its automated defenses.
>
> This level changes into a tactical turn-based battle. Each round, we select actions for each operative from the menu—such as melee attacks, sidearm fire, defensive shielding, or detonating TNT collected from Level 2.
>
> Once actions are confirmed, the round executes and the enemies retaliate. Defeating the defense units fulfills the Warden's safety protocol, standing down the AI and completing the mission."

---

## 4. Group Member Contributions (5:15 – 6:35)

### Screen Action
> Keep the game window or VS Code on screen, or open the README on GitHub showing the contributions section.

#### Spoken Script
> "Here is the exact breakdown of what each team member built:
>
> **Fabian Mahdi:**
> * Built the multi-module Gradle setup (`launcher`, `core`, `lwjgl3`) and JVM run configurations.
> * Implemented the JavaFX launcher and the background thread that pre-warms the libGDX window for instant loading.
> * Engineered the custom TCP networking engine from scratch: Port 9090 for 60 Hz movement and Port 9091 for the queued event channel.
> * Built the split-screen rendering system, dual clamped cameras, and the single-PC Debug Mode.
> * Created the pixel-mask collision engine (`CollisionMask.java`) with separated hitboxes for feet (walls) and torso (combat).
> * Developed the 5x5 inventory system, the network-synced shared item slot, and the pixel-font HUD.
> * Implemented Level 1's three terminal puzzle mechanics and the dual pressure plate system.
> * Coded sidearm ballistics with forward cone filtering and raycast wall collision.
> * Built Level 2's core pickup state machine and the emergency meltdown countdown timer.
>
> **Myself (Sadia Afrin Aurthy):**
> * Designed and implemented the Level 3 turn-based combat system, including `TurnManager`, `Level3Controller`, and the turn action UI panels.
> * Built the Level 3 networking protocol (`Level3ActionMessage`, `Level3TurnStateMessage`, `Level3EndingMessage`) for turn synchronization.
> * Integrated the visual assets and animations for the Spider Warden, Defense Drones, and Security Turrets.
> * Set up the Level 2 map base and wrote the loot spawn spacing algorithm to prevent items from clustering.
> * Fixed critical networking bugs, including wave spawn staggering, cross-client popup sync, hit visual feedback, and restart loops.
>
> **Arefin Mahim:**
> * Set up the initial Tiled map foundation and player sprite animations.
> * Built the early Level 1 swarm movement logic and player health tracking.
> * Designed the Level 2 loot system data structures and created the item assets for ammo, medkits, shield cells, and TNT.
> * Implemented weapon ammo consumption and integrated weapon actions into Level 3 turn combat."

---

## 5. Conclusion & Repository Verification (6:35 – 7:00)

### Screen Action
> Switch to browser showing the GitHub repository: `https://github.com/sadiaaurthy/NOX-SYNC`. Show `README.md` and the Presentation Video link section.

#### Spoken Script
> "To conclude, FableOps delivers on all core goals from our proposal: custom socket networking, strict cooperative locks, three complete playable levels, and an integrated debug mode for single-machine demonstration.
>
> All source code, commit history, and build instructions are available on our GitHub repository at `sadiaaurthy/NOX-SYNC`. The README contains the link to this video presentation.
>
> Thank you, sir, for your time and guidance."

---

## Quick Recording Checklist

1. **Pre-build:** Run `.\gradlew.bat launcher:installDist` before starting the recording so the launcher starts immediately.
2. **Start in Debug Mode:** Press `D` on the launcher to open the split-screen debug window.
3. **Use the `K` Key:**
   - In **Level 1**: After solving/failing one terminal code, press `K` to skip through the remaining terminal puzzles to reach the pressure plates immediately.
   - In **Level 2**: After showing the 5x5 inventory and shared slot, press `K` to toggle the core pickup directly, starting the timer and enemy wave.
4. **No Slides / No Multi-Window:** Pure single-screen game recording; no PPT slides.
5. **Pacing:** Estimated video length is **5 to 6.5 minutes**, leaving a comfortable 3+ minute buffer under the 10-minute limit.
