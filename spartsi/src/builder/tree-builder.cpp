#include "tree-builder.hpp"

namespace spartsi {

    namespace builder {

        void error(view_of<std::string> what_happened, view_of<std::string> reason, view_of<std::string> who = "") {
            auto msg = what_happened + "; reason: {" + reason + "};";
            if(who.size() != 0) msg += "called with: " + who;
            throw std::runtime_error(msg);
        }

        void comment_buffer::operator+=(view_of<str_t> str) {
            data += str + "\n";
        }

        str_t comment_buffer::pull() {
            auto copy = data;
            data.clear();
            return copy.empty()? "" : str_t(copy.begin(), copy.end()-1);
        }


        tree_builder &tree_builder::treestructinfo(view_of<str_t> ver) {
            root->version = ver;
            root->comment = comment.pull();

            nodes.push(root);
            return *this;
        }

        tree_builder &tree_builder::operator()(view_of<str_t> str) {
            comment += str;
            return *this;
        }

        tree_builder &tree_builder::name(view_of<str_t> name) {
            root->name = name;
            return *this;
        }

        tree_builder &tree_builder::end_tree() {
            pop_node();
            if(nodes.size() != 0)
                error("Failed to end tree", "=> nodes.size() != 0");
            return *this;
        }

        tree_builder::node_t::shared tree_builder::get() {
            return root;
        }

        tree_builder &tree_builder::node(view_of<str_t> name) {
            if(nodes.empty())
                error("Failed to create node", "=> nodes.empty()", name);

            nodes.push(nodes.top()->spawn_child(name, comment.pull()));
            return *this;
        }

        tree_builder &tree_builder::end_node() {
            pop_node();
            return *this;
        }

        tree_builder &tree_builder::attr(view_of<str_t> name, view_of<str_t> value) {
            if(nodes.empty())
                error("Failed to create attr", "=> nodes.empty()", name);

            nodes.top()->attributes[name] = std::make_pair(value, comment.pull());
            return *this;
        }

        tree_builder &tree_builder::req_attr(view_of<str_t> name) {
            if(nodes.empty())
                error("Failed to declare ref attr", "=> nodes.empty()", name);

            auto &attrib = nodes.top()->attributes[name];
            attrib = std::make_pair("", comment.pull());

            ref_attrs.push_front(ref(attrib));
            return *this;
        }

        tree_builder &tree_builder::ref_attr(view_of<str_t> name, view_of<str_t> value) {
            if(nodes.size() != 0)
                error("Failed to define ref attr", "=> nodes.size() != 0", name);

            if(ref_attrs.empty())
                error("Failed to define ref attr", "=> ref_attrs.empty()", name);

            //todo: check ref attr name

            auto &attr = ref_attrs.back().get();
            attr.first = value;
            if(attr.second.back() != '\n') attr.second += '\n';
            attr.second += comment.pull();
            ref_attrs.pop_back();
            return *this;
        }

        tree_builder &tree_builder::req_node(view_of<str_t> name) {
            if(nodes.empty())
                error("Failed to declare ref node", "=> nodes.empty()", name);

            ref_nodes.push_front(nodes.top()->spawn_child(name, comment.pull()));
            return *this;
        }

        tree_builder &tree_builder::ref_node(view_of<str_t> name) {
            if(nodes.size() != 0)
                error("Failed to define ref node", "=> nodes.size() != 0", name);

            if(ref_nodes.empty())
                error("Failed to define ref node", "=> ref_nodes.empty()");

            auto &ref_node = ref_nodes.back();

            if(ref_node->name != name)
                error("Name does not match", ref_node->name, name);

            if(ref_node->comment.back() != '\n') ref_node->comment += '\n';
            ref_node->comment += comment.pull();

            nodes.push(ref_node);
            ref_nodes.pop_back();
            return *this;
        }

        tree_builder &tree_builder::end_ref_node() {
            return end_node();
        }

        tree_builder &tree_builder::tree(view_of<str_t> name, node_t::shared instance) {
            nodes.top()->children[name] = instance;
            nodes.top()->alternative_comments[name] = comment.pull();
            return *this;
        }

        void tree_builder::pop_node() {
            if(nodes.empty())
                error("Failed to pop node", "=> nodes.empty()");
            nodes.pop();
        }

        tree_builder build() {
            return tree_builder{};
        }


    }

}
