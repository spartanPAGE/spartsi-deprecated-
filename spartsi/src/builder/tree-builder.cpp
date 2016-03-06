#include "tree-builder.hpp"

namespace spartsi {

    namespace builder {

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

        tree_builder::node_t::shared tree_builder::end_tree() { return root; }

        tree_builder &tree_builder::node(view_of<str_t> name) {
            nodes.push(nodes.top()->spawn_child(name, comment.pull()));
            return *this;
        }

        tree_builder &tree_builder::end_node() {
            nodes.pop();
            return *this;
        }

        tree_builder &tree_builder::attr(view_of<str_t> name, view_of<str_t> value) {
            nodes.top()->attributes[name] = std::make_pair(value, comment.pull());
            return *this;
        }


        tree_builder build() {
            return tree_builder{};
        }
    }

}
