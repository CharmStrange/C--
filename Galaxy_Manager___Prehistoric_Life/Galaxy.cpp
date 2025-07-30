#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

// Option 1: Using a struct/class directly (preferred for simplicity and RAII)
struct InputBuffer {
    std::string buffer;
    // We can often infer buffer_length from buffer.length() or buffer.size()
    // input_length can be an int or size_t, representing actual characters read.
    size_t input_length = 0; // Initialize directly in the struct

    // Constructor to ensure proper initialization
    InputBuffer() : input_length(0) {} // Default constructor

    // If you need to initialize with content, you can add another constructor:
    explicit InputBuffer(const std::string& initial_content)
        : buffer(initial_content), input_length(initial_content.length()) {}
};

// Option 2: Using a class with a private constructor and a static factory method
// This is more common when you want to control object creation more strictly,
// or if the constructor itself needs complex logic that might fail.
// For a simple buffer, Option 1 is generally sufficient.

class InputBuffurWithFactory {
public:
	string buffer;
	size_t input_length;
	
	// Static factory method to create an instance
	static unique_ptr<InputBuffurWithFactory> create() {
		auto newBuffur = make_unique<InputBuffurWithFactory>(); // Using make_unique for exception-safe memory management
		newBuffur -> input_length = 0; // Explicitly initialize
		// buffer (string) is default-constructed to be empty
		return newBuffer;
	}

private:
	// Private constructor to force creation through the static method
	InputBuffurWithFactory() = default;
	InputBuffurWithFactory(const InputBuffurWithFactory&) = delete; // Prevent copying (optional, but good practice for unique resources)
	InputBuffurWithFactory& operator = (const InputBuffurWithFactory&) = delete;
}

// Core Game Manager
class GameManager {
	
};

// Galactic Layer
class Player {
	
};

class Galaxy {
	
};

class StarSystem {
	
};

class Planets {
public:
	enum class PlanetsType {
    // Basic / Common Types
    Terrestrial,        // Earth-like, potentially habitable, diverse biomes
    GasGiant,           // Huge, gaseous, no solid surface, useful for rare gases/resources in atmosphere
    Barren,             // Rocky, airless, no life, but good for mining raw minerals
    IceWorld,           // Covered in thick ice, potential for frozen water/minerals beneath, extreme cold
    DesertWorld,        // Arid, dry, scarce water, sandstorms, specialized life
    OceanWorld,         // Mostly covered in water, deep sea biomes, marine life
    VolcanicWorld,      // High geological activity, lava flows, rich in geothermal energy/rare metals, extreme heat

    // More Specialized / Exotic Types
    JungleWorld,        // Dense, humid, lush vegetation, high biodiversity, challenging exploration
    SwampWorld,         // Wet, marshy, low-lying, unique flora/fauna, disease potential
    AmoebaWorld,        // Covered in a single, massive, primordial organism (or colony of organisms)
    FungalWorld,        // Dominated by massive fungal growth, spores, unique biochemicals
    CrystalWorld,       // Features massive crystal formations, rare mineral deposits, beautiful but dangerous terrain
    RadioactiveWorld,   // High radiation, remnants of ancient catastrophes, dangerous but rich in rare elements
    StormWorld,         // Perpetual massive storms, dangerous for exploration, but may have unique atmospheric resources
    Arboreum,           // Dominated by colossal, ancient trees that form entire biomes or continents
    TerraformedCandidate, // A barren or hostile world with the potential for terraforming
    SingularityAnomaly, // A rare, highly unstable world near a black hole or spatial anomaly, dangerous but rewarding
    MushroomWorld, // Dominated by vast, diverse fungal ecosystems.
    MethaneOceanWorld // Instead of water, large oceans of liquid methane, with unique life adapted to it.
	}
	
	enum Era {
    // --- Precambrian Eon (Formation & Early Simple Life) ---
    // The longest Eon, covering Earth's formation and the rise of single-celled and early multicellular life.
    // Generally, direct interaction might be limited here, but it sets the stage for future evolution.
    HadeanEon,          // ~4.6 to 4.0 billion years ago: Planet formation, molten surface, extreme volcanism. Likely no direct player interaction beyond discovering very primitive (non-biological) resources or signs of formation.
    ArcheanEon,         // ~4.0 to 2.5 billion years ago: Formation of stable continents, early oceans, first single-celled life (prokaryotes) like bacteria and archaea. Atmosphere slowly changes.
    ProterozoicEon,     // ~2.5 billion to 541 million years ago: Rise of complex single-celled life (eukaryotes), first multicellular organisms (Ediacaran biota - soft-bodied, strange forms), significant oxygenation of the atmosphere.

    // --- Paleozoic Era (Ancient Life - Diversification of Marine & Early Land Life) ---
    // Marks the "Cambrian Explosion" and the first major ventures onto land.
    CambrianPeriod,     // ~541 to 485 million years ago: "Cambrian Explosion" - rapid diversification of complex marine life. Many phyla of animals appear. Trilobites, Anomalocaris, Wiwaxia.
    OrdovicianPeriod,   // ~485 to 443 million years ago: Diversification of marine invertebrates, first jawless fish, primitive land plants emerge (non-vascular).
    SilurianPeriod,     // ~443 to 419 million years ago: First vascular plants on land (mosses, early ferns), first bony fish, early land arthropods.
    DevonianPeriod,     // ~419 to 359 million years ago: "Age of Fish," extensive fish diversity, first amphibians (tetrapods) move onto land, formation of large forests.
    CarboniferousPeriod,// ~359 to 299 million years ago: Vast swamp forests (forming coal deposits), giant insects (e.g., Meganeura), first reptiles evolve. High atmospheric oxygen.
    PermianPeriod,      // ~299 to 252 million years ago: Diversification of early reptiles (e.g., Dimetrodon, Gorgonopsians), synapsids (mammal-like reptiles). Ends with the "Great Dying" extinction event.

    // --- Mesozoic Era (Middle Life - Age of Dinosaurs) ---
    // The most iconic "prehistoric" era, dominated by dinosaurs.
    TriassicPeriod,     // ~252 to 201 million years ago: Recovery from Permian extinction. Rise of dinosaurs, first true mammals (small), pterosaurs (flying reptiles), marine reptiles.
    JurassicPeriod,     // ~201 to 145 million years ago: Golden Age of giant sauropods (Brachiosaurus, Diplodocus), large theropods (Allosaurus), first birds (Archaeopteryx).
    CretaceousPeriod,   // ~145 to 66 million years ago: Peak dinosaur diversity (T-Rex, Triceratops, Velociraptor), flowering plants appear. Ends with the K-Pg extinction event (asteroid impact).

    // --- Cenozoic Era (New Life - Age of Mammals & Birds) ---
    // Following the dinosaurs' extinction, mammals and birds diversify rapidly.
    PaleogenePeriod,    // ~66 to 23 million years ago: Mammals and birds radiate into ecological niches left by dinosaurs. Early large mammals (e.g., Gastornis, Basilosaurus).
    NeogenePeriod,      // ~23 to 2.6 million years ago: Further diversification of mammals (e.g., saber-toothed cats, mastodons), grasslands expand, early hominids appear (but not "sentient species" in a galactic sense).
    QuaternaryPeriod,   // ~2.6 million years ago to present (but only up to the point of "advanced" life): Ice ages (Pleistocene Epoch), megafauna (mammoths, dire wolves). This period would end *before* any galactic civilization would form or colonize.

    // --- Fictional / Alien Prehistoric Variants ---
    // If you want to expand beyond Earth's specific timeline but keep it "prehistoric":
    PrimordialSoupEra,  // Planet dominated by early, complex biochemical reactions, proto-life forms, very alien.
    ArchaicMegafloraEra,// Era defined by incredibly vast and ancient plant-like organisms dominating the planet.
    GigafaunaEpoch,     // A period where exceptionally large creatures (non-dinosaur, unique to this planet) were dominant.
    SymbioticBloomEra,  // An era where life forms evolved highly interconnected, symbiotic relationships, leading to unique ecosystems.
    MassExtinctionRecovery, // The period immediately following a major extinction event, where a few survivor species are beginning to re-diversify.
    BioLuminescantAge   // An era where a significant portion of the flora and/or fauna exhibit strong bioluminescence.
	}
};

class Technology {
	
};

// Prehistoric Layer
class Biome {
	
};

class Creature {
	
};

class Planet {
	enum class PlanetsType {
    // Basic / Common Types
    Terrestrial,        // Earth-like, potentially habitable, diverse biomes
    GasGiant,           // Huge, gaseous, no solid surface, useful for rare gases/resources in atmosphere
    Barren,             // Rocky, airless, no life, but good for mining raw minerals
    IceWorld,           // Covered in thick ice, potential for frozen water/minerals beneath, extreme cold
    DesertWorld,        // Arid, dry, scarce water, sandstorms, specialized life
    OceanWorld,         // Mostly covered in water, deep sea biomes, marine life
    VolcanicWorld,      // High geological activity, lava flows, rich in geothermal energy/rare metals, extreme heat

    // More Specialized / Exotic Types
    JungleWorld,        // Dense, humid, lush vegetation, high biodiversity, challenging exploration
    SwampWorld,         // Wet, marshy, low-lying, unique flora/fauna, disease potential
    AmoebaWorld,        // Covered in a single, massive, primordial organism (or colony of organisms)
    FungalWorld,        // Dominated by massive fungal growth, spores, unique biochemicals
    CrystalWorld,       // Features massive crystal formations, rare mineral deposits, beautiful but dangerous terrain
    RadioactiveWorld,   // High radiation, remnants of ancient catastrophes, dangerous but rich in rare elements
    StormWorld,         // Perpetual massive storms, dangerous for exploration, but may have unique atmospheric resources
    Arboreum,           // Dominated by colossal, ancient trees that form entire biomes or continents
    TerraformedCandidate, // A barren or hostile world with the potential for terraforming
    SingularityAnomaly, // A rare, highly unstable world near a black hole or spatial anomaly, dangerous but rewarding
    MushroomWorld, // Dominated by vast, diverse fungal ecosystems.
    MethaneOceanWorld // Instead of water, large oceans of liquid methane, with unique life adapted to it.
	}
	
	enum Era {
    // --- Precambrian Eon (Formation & Early Simple Life) ---
    // The longest Eon, covering Earth's formation and the rise of single-celled and early multicellular life.
    // Generally, direct interaction might be limited here, but it sets the stage for future evolution.
    HadeanEon,          // ~4.6 to 4.0 billion years ago: Planet formation, molten surface, extreme volcanism. Likely no direct player interaction beyond discovering very primitive (non-biological) resources or signs of formation.
    ArcheanEon,         // ~4.0 to 2.5 billion years ago: Formation of stable continents, early oceans, first single-celled life (prokaryotes) like bacteria and archaea. Atmosphere slowly changes.
    ProterozoicEon,     // ~2.5 billion to 541 million years ago: Rise of complex single-celled life (eukaryotes), first multicellular organisms (Ediacaran biota - soft-bodied, strange forms), significant oxygenation of the atmosphere.

    // --- Paleozoic Era (Ancient Life - Diversification of Marine & Early Land Life) ---
    // Marks the "Cambrian Explosion" and the first major ventures onto land.
    CambrianPeriod,     // ~541 to 485 million years ago: "Cambrian Explosion" - rapid diversification of complex marine life. Many phyla of animals appear. Trilobites, Anomalocaris, Wiwaxia.
    OrdovicianPeriod,   // ~485 to 443 million years ago: Diversification of marine invertebrates, first jawless fish, primitive land plants emerge (non-vascular).
    SilurianPeriod,     // ~443 to 419 million years ago: First vascular plants on land (mosses, early ferns), first bony fish, early land arthropods.
    DevonianPeriod,     // ~419 to 359 million years ago: "Age of Fish," extensive fish diversity, first amphibians (tetrapods) move onto land, formation of large forests.
    CarboniferousPeriod,// ~359 to 299 million years ago: Vast swamp forests (forming coal deposits), giant insects (e.g., Meganeura), first reptiles evolve. High atmospheric oxygen.
    PermianPeriod,      // ~299 to 252 million years ago: Diversification of early reptiles (e.g., Dimetrodon, Gorgonopsians), synapsids (mammal-like reptiles). Ends with the "Great Dying" extinction event.

    // --- Mesozoic Era (Middle Life - Age of Dinosaurs) ---
    // The most iconic "prehistoric" era, dominated by dinosaurs.
    TriassicPeriod,     // ~252 to 201 million years ago: Recovery from Permian extinction. Rise of dinosaurs, first true mammals (small), pterosaurs (flying reptiles), marine reptiles.
    JurassicPeriod,     // ~201 to 145 million years ago: Golden Age of giant sauropods (Brachiosaurus, Diplodocus), large theropods (Allosaurus), first birds (Archaeopteryx).
    CretaceousPeriod,   // ~145 to 66 million years ago: Peak dinosaur diversity (T-Rex, Triceratops, Velociraptor), flowering plants appear. Ends with the K-Pg extinction event (asteroid impact).

    // --- Cenozoic Era (New Life - Age of Mammals & Birds) ---
    // Following the dinosaurs' extinction, mammals and birds diversify rapidly.
    PaleogenePeriod,    // ~66 to 23 million years ago: Mammals and birds radiate into ecological niches left by dinosaurs. Early large mammals (e.g., Gastornis, Basilosaurus).
    NeogenePeriod,      // ~23 to 2.6 million years ago: Further diversification of mammals (e.g., saber-toothed cats, mastodons), grasslands expand, early hominids appear (but not "sentient species" in a galactic sense).
    QuaternaryPeriod,   // ~2.6 million years ago to present (but only up to the point of "advanced" life): Ice ages (Pleistocene Epoch), megafauna (mammoths, dire wolves). This period would end *before* any galactic civilization would form or colonize.

    // --- Fictional / Alien Prehistoric Variants ---
    // If you want to expand beyond Earth's specific timeline but keep it "prehistoric":
    PrimordialSoupEra,  // Planet dominated by early, complex biochemical reactions, proto-life forms, very alien.
    ArchaicMegafloraEra,// Era defined by incredibly vast and ancient plant-like organisms dominating the planet.
    GigafaunaEpoch,     // A period where exceptionally large creatures (non-dinosaur, unique to this planet) were dominant.
    SymbioticBloomEra,  // An era where life forms evolved highly interconnected, symbiotic relationships, leading to unique ecosystems.
    MassExtinctionRecovery, // The period immediately following a major extinction event, where a few survivor species are beginning to re-diversify.
    BioLuminescantAge   // An era where a significant portion of the flora and/or fauna exhibit strong bioluminescence.
	}
	
	Planet(string name, PlanetsType type);
	
	void displayInfo();
    void addResource(string resourceName, int amount);
	void removeResource(string resourceName, int amount);
    void simulatePrehistoricEra();
};

class Event {
	
};

// Utility Layer
class Resource {};
class MenuSystem {};
class Logger {};

int main(void){
	return 0;
}
