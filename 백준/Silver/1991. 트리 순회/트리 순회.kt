const val THIS = 0
const val LEFT = 1
const val RIGHT = 2

fun main() {
    val N = readln().toInt()
    val tree = Array(N) { Array(3) { '.' } }
    for (i in 0 until N) readln().split(' ').forEachIndexed { idx, str -> tree[i][idx] = str.first() }

    preorder(tree, tree[0][0])
    println()
    inorder(tree, tree[0][0])
    println()
    postorder(tree, tree[0][0])
}

fun preorder(tree: Array<Array<Char>>, char: Char) {
    for (i in tree.indices) {
        if (tree[i][THIS] == char) {
            print(char)
            if (tree[i][LEFT] != '.') preorder(tree, tree[i][LEFT])
            if (tree[i][RIGHT] != '.') preorder(tree, tree[i][RIGHT])
            break
        }
    }
}

fun inorder(tree: Array<Array<Char>>, char: Char) {
    for (i in tree.indices) {
        if (tree[i][THIS] == char) {
            if (tree[i][LEFT] != '.') inorder(tree, tree[i][LEFT])
            print(char)
            if (tree[i][RIGHT] != '.') inorder(tree, tree[i][RIGHT])
            break
        }
    }
}

fun postorder(tree: Array<Array<Char>>, char: Char) {
    for (i in tree.indices) {
        if (tree[i][THIS] == char) {
            if (tree[i][LEFT] != '.') postorder(tree, tree[i][LEFT])
            if (tree[i][RIGHT] != '.') postorder(tree, tree[i][RIGHT])
            print(char)
            break
        }
    }
}
