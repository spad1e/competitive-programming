int mxdif = -1;
KeyT ret;

int dfs(node *n) {
    if (n == nullptr) return -1;
    int lsz = dfs(n->left), rsz = dfs(n->right);
    if (abs(lsz - rsz) > mxdif) {
        mxdif = abs(lsz - rsz);
        ret = (n->data).first;
    }
    else if (abs(lsz - rsz) == mxdif && mLess(n->data.first, ret)) {
        ret = (n->data).first;
    }
    return std::max(lsz, rsz) +1;
}

KeyT getValueOfMostImbalanceNode() {
    mxdif = -1;
    dfs(mRoot);
    return ret;
}
