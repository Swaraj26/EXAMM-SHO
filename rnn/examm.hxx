#ifndef EXAMM_HXX
#define EXAMM_HXX

#include <fstream>
using std::ofstream;

#include <map>
using std::map;

#include <sstream>
using std::ostringstream;

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include "rnn_genome.hxx"
#include "speciation_strategy.hxx"
#include "common/weight_initialize.hxx"

class EXAMM {
    private:
        int32_t population_size;
        int32_t number_islands;

        vector< vector<RNN_Genome*> > genomes;

        int32_t max_genomes;
        int32_t total_bp_epochs;

        int32_t extinction_event_generation_number;
        string island_ranking_method;

        string speciation_method;
        string repopulation_method;
        int32_t repopulation_mutations;
        bool repeat_extinction;
        int32_t epochs_acc_freq;

        SpeciationStrategy *speciation_strategy;

        double species_threshold;
        double fitness_threshold;
        double neat_c1;
        double neat_c2;
        double neat_c3;

        int32_t edge_innovation_count;
        int32_t node_innovation_count;

        map<string, int32_t> inserted_from_map;
        map<string, int32_t> generated_from_map;

        int32_t number_inputs;
        int32_t number_outputs;
        int32_t bp_iterations;
        double learning_rate;

        double initial_learning_rate_min;
        double initial_learning_rate_max;
        double learning_rate_min;
        double learning_rate_max;

        bool use_high_threshold;
        double high_threshold;

        bool use_low_threshold;
        double low_threshold;

        bool use_regression;
        bool use_dropout;
        double dropout_probability;

        minstd_rand0 generator;
        uniform_real_distribution<double> rng_0_1;
        uniform_real_distribution<double> rng_crossover_weight;

        int32_t min_recurrent_depth;
        int32_t max_recurrent_depth;


        bool epigenetic_weights;

        double more_fit_crossover_rate;
        double less_fit_crossover_rate;

        double clone_rate;

        double add_edge_rate;
        double add_recurrent_edge_rate;
        double enable_edge_rate;
        double disable_edge_rate;
        double split_edge_rate;

        double add_node_rate;
        double enable_node_rate;
        double disable_node_rate;
        double split_node_rate;
        double merge_node_rate;

        

        //SY: New Hyperparameter variables
        double initial_clone_rate;
        double initial_clone_rate_min;
        double initial_clone_rate_max;
        double clone_rate_min;
        double clone_rate_max;

        
        double initial_add_edge_rate;
        double initial_add_edge_rate_min;
        double initial_add_edge_rate_max;
        double add_edge_rate_min;
        double add_edge_rate_max;
        
        double initial_add_recurrent_edge_rate;
        double initial_add_recurrent_edge_rate_min;
        double initial_add_recurrent_edge_rate_max;
        double add_recurrent_edge_rate_min;
        double add_recurrent_edge_rate_max;
        
        double initial_enable_edge_rate;
        double initial_enable_edge_rate_min;
        double initial_enable_edge_rate_max;
        double enable_edge_rate_min;
        double enable_edge_rate_max;
        
        double initial_disable_edge_rate;
        double initial_disable_edge_rate_min;
        double initial_disable_edge_rate_max;
        double disable_edge_rate_min;
        double disable_edge_rate_max;
        
        double initial_split_edge_rate;
        double initial_split_edge_rate_min;
        double initial_split_edge_rate_max;
        double split_edge_rate_min;
        double split_edge_rate_max;
        
        double initial_add_node_rate;
        double initial_add_node_rate_min;
        double initial_add_node_rate_max;
        double add_node_rate_min;
        double add_node_rate_max;
        
        double initial_enable_node_rate;
        double initial_enable_node_rate_min;
        double initial_enable_node_rate_max;
        double enable_node_rate_min;
        double enable_node_rate_max;
        
        double initial_disable_node_rate;
        double initial_disable_node_rate_min;
        double initial_disable_node_rate_max;
        double disable_node_rate_min;
        double disable_node_rate_max;
        
        double initial_split_node_rate;
        double initial_split_node_rate_min;
        double initial_split_node_rate_max;
        double split_node_rate_min;
        double split_node_rate_max;
        
        double initial_merge_node_rate;
        double initial_merge_node_rate_min;
        double initial_merge_node_rate_max;
        double merge_node_rate_min;
        double merge_node_rate_max;
        



        // TODO SY remove commented variables
        // double initial_learning_rate_delta_min;
        // double initial_learning_rate_delta_max;
        // double learning_rate_delta_min;
        // double learning_rate_delta_max;

        // double initial_high_threshold_min;
        // double initial_high_threshold_max;
        // double high_threshold_min;
        // double high_threshold_max;

        // double initial_high_threshold_delta_min;
        // double initial_high_threshold_delta_max;
        // double high_threshold_delta_min;
        // double high_threshold_delta_max;

        // double initial_low_threshold_min;
        // double initial_low_threshold_max;
        // double low_threshold_min;
        // double low_threshold_max;

        // double initial_low_threshold_delta_min;
        // double initial_low_threshold_delta_max;
        // double low_threshold_delta_min;
        // double low_threshold_delta_max;

        // double initial_dropout_probability_min;
        // double initial_dropout_probability_max;
        // double dropout_probability_min;
        // double dropout_probability_max;


        vector<int> possible_node_types;

        vector<string> op_log_ordering;
        map<string, int32_t> inserted_counts;
        map<string, int32_t> generated_counts;

        string output_directory;
        ofstream *log_file;
        ofstream *op_log_file;

        vector<string> input_parameter_names;
        vector<string> output_parameter_names;

        string normalize_type;
        map<string,double> normalize_mins;
        map<string,double> normalize_maxs;
        map<string,double> normalize_avgs;
        map<string,double> normalize_std_devs;

        WeightType weight_initialize;
        WeightType weight_inheritance;
        WeightType mutated_component_weight;

        ostringstream memory_log;

        std::chrono::time_point<std::chrono::system_clock> startClock;

        string  genome_file_name;

        bool start_filled;

    public:
        EXAMM(  int32_t _population_size,
                int32_t _number_islands,
                int32_t _max_genomes,
                int32_t _extinction_event_generation_number,
                int32_t _islands_to_exterminate,
                string _island_ranking_method,
                string _repopulation_method,
                int32_t _repopulation_mutations,
                bool _repeat_extinction,
                int32_t _epochs_acc_freq,
                string _speciation_method,
                double _species_threshold,
                double _fitness_threshold,
                double _neat_c1,
                double _neat_c2,
                double _neat_c3,
                const vector<string> &_input_parameter_names,
                const vector<string> &_output_parameter_names,
                string _normalize_type,
                const map<string,double> &_normalize_mins,
                const map<string,double> &_normalize_maxs,
                const map<string,double> &_normalize_avgs,
                const map<string,double> &_normalize_std_devs,
                WeightType _weight_initialize,
                WeightType _weight_inheritance,
                WeightType _mutated_component_weight,
                int32_t _bp_iterations,
                double _learning_rate,
                bool _use_high_threshold,
                double _high_threshold,
                bool _use_low_threshold,
                double _low_threshold,
                bool _use_dropout,
                double _dropout_probability,
                int32_t _min_recurrent_depth,
                int32_t _max_recurrent_depth,
                bool _use_regression,
                string _output_directory,
                RNN_Genome *seed_genome,
                bool _start_filled);


        ~EXAMM();

        void print();
        void update_log();
        void write_memory_log(string filename);

        void set_possible_node_types(vector<string> possible_node_type_strings);

        uniform_int_distribution<int32_t> get_recurrent_depth_dist();

        int get_random_node_type();

        void generate_examm_initial_hyperparameters(double &clone_rate, double &add_edge_rate, double &add_recurrent_edge_rate, double &enable_edge_rate, double &disable_edge_rate, double &split_edge_rate, double &add_node_rate, double &enable_node_rate, double &disable_node_rate, double &split_node_rate, double &merge_node_rate);

        void generate_examm_simplex_hyperparameters(double &clone_rate, double &add_edge_rate, double &add_recurrent_edge_rate, double &enable_edge_rate, double &disable_edge_rate, double &split_edge_rate, double &add_node_rate, double &enable_node_rate, double &disable_node_rate, double &split_node_rate, double &merge_node_rate);

        void generate_initial_hyperparameters(double &learning_rate);

        void generate_simplex_hyperparameters(double &learning_rate);

        RNN_Genome* generate_genome(int32_t seed_genome_stirs = 0);
        bool insert_genome(RNN_Genome* genome);

        void mutate(int32_t max_mutations, RNN_Genome *p1);

        void attempt_node_insert(vector<RNN_Node_Interface*> &child_nodes, const RNN_Node_Interface *node, const vector<double> &new_weights);
        void attempt_edge_insert(vector<RNN_Edge*> &child_edges, vector<RNN_Node_Interface*> &child_nodes, RNN_Edge *edge, RNN_Edge *second_edge, bool set_enabled);
        void attempt_recurrent_edge_insert(vector<RNN_Recurrent_Edge*> &child_recurrent_edges, vector<RNN_Node_Interface*> &child_nodes, RNN_Recurrent_Edge *recurrent_edge, RNN_Recurrent_Edge *second_edge, bool set_enabled);
        RNN_Genome* crossover(RNN_Genome *p1, RNN_Genome *p2);

        double get_best_fitness();
        double get_worst_fitness();
        RNN_Genome* get_best_genome();
        RNN_Genome* get_worst_genome();

        string get_output_directory() const;
        RNN_Genome* generate_for_transfer_learning(string file_name, int extra_inputs, int extra_outputs) ;

        void check_weight_initialize_validity();
};

#endif
